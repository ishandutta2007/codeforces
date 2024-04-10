#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<ll , ll> cnt;
map<pll ,ll> mp;

int main()
{
    fast_io;

    ll n , k;
    cin >> n >> k;

    ll a[n] , b[n];
    vector<pll> vec;
    for(int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i < n ;i++)
    {
        cin >> b[i];
        vec.push_back({a[i] , b[i]});
        mp[vec[i]] = i;
    }
    Sort(vec);

    vector<ll> ans(n);
    for(int i = 0 ; i < n ; i++)
    {
        ans[mp[vec[i]]] = -1;
        if(i > 0)
        {
            if(vec[i].X == vec[i - 1].X)
            {
                ans[mp[vec[i]]] = ans[mp[vec[i - 1]]] - vec[i - 1].Y + vec[i].Y;
            }
        }
        if(i == 0)
        {
            ans[mp[vec[i]]] = vec[i].Y;
        }
        if(ans[mp[vec[i]]] == -1)
        {
            ll x = k;
            ans[mp[vec[i]]] = vec[i].Y;
            map<ll , ll>::iterator it = cnt.end() ; it--;
            for(; ; it--)
            {
                ll t = min(x , it -> Y);
                ans[mp[vec[i]]] += it -> X * t;
                x -= t;
                if(x == 0 || it == cnt.begin())
                {
                    break;
                }
            }
        }
        cnt[vec[i].Y]++;
    }

    for(ll i : ans)
    {
        cout << i << ends;
    }

    return 0;
}