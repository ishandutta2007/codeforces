#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int mod = 1000000007;
const int N = 1e6 + 10;
const int lgN = 21;
char s[N];
int a[N];
int n, m, o;

int c[lgN][N];
void sufarr()
{
    static int p[N];
    static vector<int> cnt[N]; int ccnt = 0;
    Loop(i,0,n) cnt[s[i]].push_back(i);
    Loop(i,0,256)
    {
        reverse(all(cnt[i]));
        while(cnt[i].size())
            p[ccnt++] = cnt[i].back(),
            cnt[i].pop_back();
    }
    c[0][p[0]] = 0; Loop(i,1,n) c[0][p[i]] = c[0][p[i-1]] + (s[p[i]] != s[p[i-1]]);
    Loop(k,0,lgN-1)
    {
        ccnt = 0;
        Loop(i,0,n) cnt[c[k][((p[i]-(1<<k))%n+n)%n]].push_back(((p[i]-(1<<k))%n+n)%n);
        Loop(i,0,n)
        {
            if(cnt[i].empty()) continue;
            reverse(all(cnt[i]));
            while(cnt[i].size())
                p[ccnt++] = cnt[i].back(),
                cnt[i].pop_back();
        }
        c[k+1][p[0]] = 0;
        Loop(i,1,n)
            c[k+1][p[i]] = c[k+1][p[i-1]] +
             (c[k][p[i-1]] != c[k][p[i]] || c[k][(p[i-1]+(1<<k))%n] != c[k][(p[i]+(1<<k))%n]);
    }
}

int lcp(int a, int b)
{
    int ans = 0;
    LoopR(k,0,lgN)
    {
        if(c[k][a] == c[k][b]) {
            ans += 1<<k;
            a += 1<<k;
            b += 1<<k;
        }
    }
    return ans;
}

int main()
{
    FAST;
    cin >> m >> o;
    cin >> s;
    n = strlen(s) + 1;
    sufarr();
    Loop(i,0,o)
    {
        cin >> a[i]; a[i]--;
        if(i && a[i] - a[i-1] < n-1)
        {
            int x = lcp(0, a[i] - a[i-1]);
            if(a[i] - a[i-1] + x != n-1) Kill(0);
        }
    }
    ll ans = 1;
    int lst = -1;
    Loop(i,0,m)
    {
        if(lst+1 < o && a[lst+1] <= i) lst++;
        if(!~lst || a[lst]+n-1 <= i) ans = ans*26 % mod;
    }
    cout << ans << '\n';
}