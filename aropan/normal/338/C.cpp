#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int MAXN = 8;
const int MAXM = 6561; // 3^8
const int MAXX = 1000001;
const int INF = (int)1e+9 + 7;

int n;
long long a[MAXN];
int t[MAXN];

int f[MAXM];
int F[MAXX];
vector <int> p;

map <long long, int> m;
int ans = INF;

int width(long long x)
{
    if (m.find(x) != m.end())
        return m[x];
    int &res = m[x];
    res = 0;
    for (int i = 0; i < (int)p.size() && p[i] * (long long)p[i] <= x; i++)
        while (x % p[i] == 0)
        {
            res += 1;
            x /= p[i];
        }
    res += (x != 1);
    return res;
}


void rec(int m, int j, int r, long long x)
{
    if (m == n)
    {
        f[j] = min(f[j], r + width(x));
        return;
    }
    
    j *= 3;

    if (t[m] == -1)
    {
        rec(m + 1, j + 1, r, x);
        return;
    }
    
    rec(m + 1, j + t[m], r, x);
    if (t[m] == 1 && x % a[m] == 0)
        rec(m + 1, j + 2, r, x / a[m]);
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    for (int i = 2; i * i < MAXX; i++)
        if (!F[i])
            for (int j = i * i; j < MAXX; j += i)
                F[j] = true;
    for (int i = 2; i < MAXX; i++)
        if (!F[i])
            p.push_back(i);
    
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        n = unique(a, a + n) - a;

        for (int i = 0; i < MAXM; i++)
            f[i] = INF;

        int x = 0;
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            x *= 3;
            if (width(a[i]) == 1)
            {
                x += 1;
                r += 1;
            }
        }

        f[x] = r;
        ans = INF;
        for (int i = 0; i < MAXM; i++)
            if (f[i] < INF)
            {
                int x = i;
                for (int j = n - 1; j >= 0; j--)
                {
                    t[j] = x % 3;
                    x /= 3;
                }
                
                int zero = 0, one = 0;
/*
                for (int j = 0; j < n; j++)
                    cout << t[j];
                cout << ": " << f[i] << endl;
//*/                
                for (int j = 0; j < n; j++)
                    if (t[j] == 0)
                    {
                        t[j] = -1;
                        rec(0, 0, f[i] + 1, a[j]);
                        t[j] = 0;
                    }

                for (int j = 0; j < n; j++)
                {
                    zero += t[j] == 0;
                    one += t[j] == 1;
                }
                
                if (zero == 0)
                    ans = min(ans, f[i] + (int)(one > 1));
            }
        cout << ans << endl;
    }

	return 0;
}