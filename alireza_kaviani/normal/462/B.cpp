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
inline int input(){int n; cin >> n ; return n;}

map<char , ll> cnt;
bool cmp(ll a , ll b)
{
    return a > b;
}

int main()
{
    fast_io;

    ll n , k , ans = 0;
    string s;
    cin >> n >> k >> s;

    vector<ll> vec;
    for(int i = 0 ; i < n ; i++)    cnt[s[i]]++;
    for(auto &i : cnt)
    {
        vec.push_back(i.Y);
    }

    sort(all(vec) , cmp);
    for(int i = 0 ; i < n ; i++)
    {
        ans += min(k , vec[i]) * min(k , vec[i]);
        k -= min(k , vec[i]);
        if(k == 0)
        {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}