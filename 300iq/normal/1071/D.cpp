#include <cmath>
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
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

vector <int> primes;

bool prie(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return (x != 1);
}

vector <int> kek;
vector <vector <int> > a;
vector <vector <int> > inp;

void rec_p(int i, int cur, int last)
{
    inp.push_back(kek);
    for (int t = 1; t <= last; t++)
    {
        if (cur * primes[i] > 1000000) break;
        cur *= primes[i];
        kek.push_back(t);
        rec_p(i + 1, cur, t);
        kek.pop_back();
    }
}

void rec(int i, int cur, int last)
{
    a.push_back(kek);
    for (int t = 1; t <= last; t++)
    {
        if (cur * (t + 1) > 1000) break;
        kek.push_back(t);
        rec(i + 1, cur * (t + 1), t);
        kek.pop_back();
    }
}

int ans[289][1001];
int mat[289][289];

const int N = 1000000 + 7;

vector <int> ugar[N];
int press[N];
bool prime[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= 1000; i++)
    {
        if (prie(i)) primes.push_back(i);
    }
    rec(0, 1, 1000000);
    rec_p(0, 1, 123);
    vector <int> divs;
    for (int j = 0; j < (int) a.size(); j++)
    {
        int sum = 1;
        for (int x : a[j])
        {
            sum *= (x + 1);
        }
        divs.push_back(sum);
    }
    for (int i = 0; i < (int) inp.size(); i++)
    {
        for (int x = 1; x <= 1000; x++) ans[i][x] = 1e9;
        for (int j = 0; j < (int) a.size(); j++)
        {
            int sum = 0;
            for (int t = 0; t < max((int) inp[i].size(), (int) a[j].size()); t++)
            {
                int x = (t < (int) inp[i].size() ? inp[i][t] : 0);
                int y = (t < (int) a[j].size() ? a[j][t] : 0);
                sum += abs(x - y);
            }
            ans[i][divs[j]] = min(ans[i][divs[j]], sum);
        }
    }
    int sum = 0;
    map <vector <int>, int> ind;
    for (int i = 0; i < (int) inp.size(); i++)
    {
        ind[inp[i]] = i;
        for (int j = 0; j < (int) inp.size(); j++)
        {
            int mx = 1e9;
            int last = 0;
            for (int x = 1; x <= 1000; x++)
            {
                if (ans[i][x] + ans[j][x] < mx)
                {
                    mx = ans[i][x] + ans[j][x];
                    last = x;
                }
            }
            mat[i][j] = mx;
        }
    }
    prime[1] = false;
    for (int i = 2; i < N; i++)
    {
        prime[i] = true;
    }
    for (int i = 2; i < N; i++)
    {
        if (prime[i])
        {
            for (int j = i; j < N; j += i)
            {
                if (i != j)
                {
                    prime[j] = 0;
                }
                int x = j;
                int deg = 0;
                while (x % i == 0)
                {
                    x /= i;
                    deg++;
                }
                ugar[j].push_back(deg);
            }
        }
    }
    for (int i = 1; i < N; i++)
    {
        sort(ugar[i].rbegin(), ugar[i].rend());
        assert(ind.count(ugar[i]));
        press[i] = ind[ugar[i]];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << mat[press[a]][press[b]] << '\n';
    }
}