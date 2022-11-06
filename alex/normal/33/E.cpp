#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

double const pi = 3.1415926535897932384626433832795;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 101;
int const MMAX = 1441 * 30;

int n, m, k, t[NMAX];
char name[NMAX][50];
bool used[MMAX];
pair <pii, pii> p[NMAX];

int ans[NMAX][MMAX];
int prev1[NMAX][MMAX];
int prev2[NMAX][MMAX];

int read_data()
{
        char ch1, ch2, ch3, ch4, ch5;
        cin >> ch1;
        while (ch1 <= ' ') cin >> ch1;
        cin >> ch2 >> ch3 >> ch4 >> ch5;
        return 60 * (10 * (ch1 - '0') + ch2 - '0') + 10 * (ch4 - '0') + ch5 - '0';
}

int WWW;

void init(int cnt)
{
        WWW = -1;
        while (cnt > 0)
        {
                WWW++;
                while (WWW < MMAX && used[WWW])
                        WWW++;
                cnt--;
        }
}

void next()
{
        WWW++;
        while (WWW < MMAX && used[WWW])
                WWW++;
}

void calc(int t)
{
        while (used[t]) t++;

        int d = 0;
        while (t >= 1440)
                t -= 1440, d++;
        cout << d  + 1 << " ";
        if (t / 60 < 10) cout << 0;
        cout << t / 60 << ":";
        if (t % 60 < 10) cout << 0;
        cout << t % 60 << " ";
}

void way(int x, int y, int now)
{
        if (x == -1)
        {
                cout << now << endl;
                return;
        }
        if (prev2[x][y] != y) now++;
        way(x - 1, prev2[x][y], now);
        if (prev2[x][y] != y)
        {
                cout << p[x - 1].fs.sc + 1 << " ";
                calc(prev2[x][y]);
                calc(y - 1);
                cout << endl;
        }
}

int main()
{
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

        cin >> m >> n >> k;
        forn(i, m)
                cin >> name[i];
        forn(i, m)
                cin >> t[i];

        seta(used, 0);
        forn(i, 4)
        {
                pii now;
                now.fs = read_data();
                char c;
                cin >> c;
                now.sc = read_data();

                forn(f, k)
                        for (int j = now.fs; j <= now.sc; j++)
                                used[j + f * 1440] = true;
        }

        forn(i, n)
        {
                char tmp[50];
                cin >> tmp;
                p[i].sc.fs = -1;
                forn(j, m)
                        if (strcmp(tmp, name[j]) == 0) p[i].sc.fs = j;

                int d;
                cin >> d;
                p[i].fs.fs = (d - 1) * 1440 + read_data();
                p[i].fs.sc = i;
                cin >> p[i].sc.sc;
        }
        sort(p, p + n);

        seta(ans, 0);
        forn(i, n)
        {
	//		cerr << clock() << endl;
                if (p[i].sc.fs >= 0) init(t[p[i].sc.fs]);
                forn(j, MMAX - 1)
                {
                        if (ans[i + 1][j] < ans[i][j])
                        {
                                ans[i + 1][j] = ans[i][j];
                                prev1[i + 1][j] = i;
                                prev2[i + 1][j] = j;
                        }
                        if (p[i].sc.fs >= 0 && p[i].fs.fs > WWW)
                                if (ans[i + 1][WWW + 1] < ans[i][j] + p[i].sc.sc)
                                {
                                        ans[i + 1][WWW + 1] = ans[i][j] + p[i].sc.sc;
                                        prev1[i + 1][WWW + 1] = i;
                                        prev2[i + 1][WWW + 1] = j;
                                }
                        if (!used[j]) next();
                }
        }

        int answer = 0, px = 0, py = 0;
        forn(j, n + 1)
                forn(i, MMAX)
                        if (answer < ans[j][i])
                        {
                                answer = ans[j][i];
                                px = j;
                                py  =i;
                        }
        cout << answer << endl;
         way(px, py, 0);
		//cerr << clock() << endl;

        return 0;
}