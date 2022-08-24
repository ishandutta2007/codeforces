/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Ildar
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>

using namespace std;

const int N = 120 + 8;

class TaskB
{
public:
    //kuk
    int score[6];
    double l[6], r[6];
    int ok[5];
    int cnt[N][5];
    int arr[5];
    int tup[5];
    //kek
    int n;
    int x;
    bool can = false;

    void rec(int i)
    {
        if (i == 5)
        {
            int sum = 0;
            bool good = true;
            for (int j = 0; j < 5; j++)
            {
                if (ok[j] > r[arr[j]] * x)
                {
                    good = false;
                    break;
                }
                if (ok[j] > l[arr[j]] * x)
                {
                    continue;
                }
                int need = (int) (l[arr[j]] * x - ok[j]);
                while ((ok[j] + need) <= l[arr[j]] * x)
                {
                    need++;
                }
                if ((ok[j] + need) > r[arr[j]] * x)
                {
                    good = false;
                    break;
                }
                if (need != 0 && cnt[0][j] == -1)
                {
                    good = false;
                    break;
                }
                tup[j] = need;
                sum = max(sum, need);
            }
            if (sum > x - n)
            {
                good = false;
            }
            else if (good)
            {
                int p_a = 0, p_b = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (cnt[0][i] != -1)
                    {
                        p_a += score[arr[i]] * (1 - cnt[0][i] / (double) 250);
                    }
                    if (cnt[1][i] != -1)
                    {
                        p_b += score[arr[i]] * (1 - cnt[1][i] / (double) 250);
                    }
                }
                if (p_a <= p_b)
                {
                    good = false;
                }
            }
            can |= good;
        }
        else
        {
            for (int a = 0; a < 6; a++)
            {
                arr[i] = a;
                rec(i + 1);
            }
        }
    }

    void solve(std::istream &in, std::ostream &out)
    {
        l[0] = 1.0 / 2.0;
        r[0] = 1;
        l[1] = 1.0 / 4.0;
        r[1] = 1.0 / 2.0;
        l[2] = 1.0 / 8.0;
        r[2] = 1.0 / 4.0;
        l[3] = 1.0 / 16.0;
        r[3] = 1.0 / 8.0;
        l[4] = 1.0 / 32.0;
        r[4] = 1.0 / 16.0;
        l[5] = -1;
        r[5] = 1.0 / 32.0;
        score[0] = 500, score[1] = 1000, score[2] = 1500, score[3] = 2000, score[4] = 2500, score[5] = 3000;
        for (int j = 0; j < 5; j++)
        {
            ok[j] = 0;
        }
        in >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                in >> cnt[i][j];
                ok[j] += (cnt[i][j] != -1);
            }
        }
        for (int m = 0; m <= 1000; m++)
        {
            x = n + m;
            can = false;
            rec(0);
            if (can)
            {
                out << m << '\n';
                return;
            }
        }
        int l = 1000, r = (int) 1e9 + 7;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            x = n + m;
            can = false;
            rec(0);
            if (can)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        if (r == (int) 1e9 + 7)
        {
            out << -1 << '\n';
        }
        else
        {
            out << r << '\n';
        }
    }
};


int main()
{
    ios::sync_with_stdio(0);
    TaskB solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}