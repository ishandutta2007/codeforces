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
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
    map<string , int> mp , mp2;
    fast_io;
    int n , k , m;
    cin >> n >> k >> m;

    string s[n];
    int a[n];
    for(int i = 0; i < n ;i++)
    {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[s[i]] = a[i];
        mp2[s[i]] = a[i];
    }

    for(int i = 0 ;i < k ; i++)
    {
        int x , minn = 2e9;
        cin >> x;
        vector<int> vec(x);
        for(int j = 0 ; j < x ;j++)
        {
            cin >> vec[j];
            vec[j]--;
            minn = min(minn , mp[s[vec[j]]]);
        }

        for(int j: vec)
        {
            mp2[s[j]] = minn;
        }
    }

    ll ans = 0ll;
    for(int i = 0; i < m ;i++)
    {
        string t;
        cin >> t;
        ans += ll(mp2[t]);
    }
    cout << ans << endl;

    return 0;
}