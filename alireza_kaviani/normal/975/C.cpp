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

int main()
{
    fast_io;

    ll n , q;
    cin >> n >> q;

    vector<ll> a(n) , k(q) , ps(q) , ps2(n);
    for(ll i = 0; i < n ; i++)
    {
        cin >> a[i];
        ps2[i] = (i == 0 ? a[i] : ps2[i - 1] + a[i]);
    }
    for(ll i = 0 ;i < q ; i++)
    {
        cin >> k[i];
        ps[i] = (i == 0 ? k[i] : ps[i - 1] + k[i]);
    }

    ll t = 0;
    vector<int> ans;
    for(int i = 0; i < q ; i++)
    {
        t += k[i];
        vector<ll>::iterator it = upper_bound(all(ps2) , t);
        ll indx = it - ps2.begin();
        if(indx == n)
        {
            t = 0;
        }
        cout << (n - indx == 0 ? n : n - indx) << endl;
    }

    return 0;
}