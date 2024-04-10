#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 700'010;
ll w[N];
map<ll, int> cnth;
int cnt[N]={};
ll ans = 0;
ll cur = 0;
ll par[N];
int a[N];
int n;

ll ter_xor(ll a, ll b)
{
    int cnt = 0;
    ll tmp = 0;
    while(a || b)
    {
        cnt++;
        tmp *= 3;
        tmp += (a+b)%3;
        a/=3;
        b/=3;
    }
    ll ans = 0;
    while(cnt--)
    {
        ans *= 3;
        ans += tmp%3;
        tmp /= 3;
    }
    return ans;
}

void addh(ll x, int v)
{
    ll tmp = cnth[x];
    cur -= tmp*(tmp-1)/2;
    tmp += v;
    cur += tmp*(tmp-1)/2;
    cnth[x] = tmp;
}

inline void add(int i)
{
    cnt[a[i]]++;
    addh(par[i+1], 1);
}
inline void remove(int i)
{
    cnt[a[i]]--;
    addh(par[i], -1);
}

int rand30()
{
    return 32768*rand() + rand();
}

ll rand60()
{
    return (1LL << 30)*rand30() + rand30();
}

int main()
{
    FAST;
    srand(time(0));
    Loop(i,0,N)
        w[i] = rand60() + 1;
    cin >> n;
    par[0] = 0; addh(0, 1);
    Loop(i,0,n)
    {
        cin >> a[i];
        par[i+1] = ter_xor(par[i], w[a[i]]);
    }
    int l = 0;
    Loop(r,0,n)
    {
        if(cnt[a[r]]==3)
        {
            ans += cur;
            while(cnt[a[r]]==3)
                remove(l++);
            ans -= cur;
        }
        add(r);
    }
    ans += cur;
    cout << ans << '\n';
}