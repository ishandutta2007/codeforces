#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

ll gcd(ll a, ll b){return b? gcd(b, a%b): a;}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        ll g = 0;
        vector<ll> a(n);
        Loop(i,0,n) cin >> a[i];
        Loop(j,0,n) g = gcd(g, abs(a[0] - a[j]));
        Loop(i,0,n)
        {
            if((g && (k-a[i])%g == 0) || k == a[i]){
                cout << "YES\n";
                goto end;
            }
        }
        cout << "NO\n";
        end:;
    }
}