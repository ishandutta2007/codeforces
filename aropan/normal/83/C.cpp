#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 55;

struct mpair
{
    string s;
    int x, y, m, c;

    mpair(string S = "", int X = 0, int Y = 0, int M = 0, int C = 0)
        : s(S), x(X), y(Y), m(M), c(C) { }
};

bool operator<(const mpair &a, const mpair &b)
{
    return
        a.s.size() > b.s.size() ||
        a.s.size() == b.s.size() && a.s > b.s;
}

const int
    xi[4] = {-1, 0, 1, 0},
    yi[4] = {0, -1, 0, 1};

set <long long> S;
priority_queue <mpair> H;

int n, m, k;
int xs, ys;
char a[MAXN][MAXN];
int o[MAXN][MAXN];
string ans;

int add(int i, int j, string s, int m, int c)
{
    if (c > k) return 0;
    long long x = (((((long long)m) << 6)+ i) << 6) + j;
    if (S.find(x) != S.end()) return 0;
    if (o[i][j] && ((o[i][j] & m) == o[i][j])) return 0;
    o[i][j] = m;
    S.insert(x);
//    printf("  +%s %d %d\n", s.c_str(), i, j);
    H.push(mpair(s, i, j, m, c));
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &a[i][j]);
            if (a[i][j] == 'S')
            {
                xs = i;
                ys = j;
            }
        }
        scanf("\n");
    }

    add(xs, ys, "", 0, 0);
    while (H.size())
    {
        mpair p = H.top();
        H.pop();

        string
            s = p.s;

        int
            x = p.x,
            y = p.y,
            mask = p.m,
            count = p.c;
//        cout << s << " " << x << " " << y << endl;

        for (int i = 0; i < 4; i++)
        {
            int
                xx = x + xi[i],
                yy = y + yi[i];

            if (xx < 1 || n < xx || yy < 1 || m < yy || a[xx][yy] == 'S') continue;


            if (a[xx][yy] == 'T')
            {
                cout << s << endl;
                return 0;
            }

            int j = a[xx][yy] - 'a';
            add(xx, yy, s + a[xx][yy], mask | (1 << j), count + (((1 << j) & mask) == 0));
        }
    }
    puts("-1");
    return 0;
}