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

map<int , int> mp;

int main()
{
    fast_io;

    int n;
    cin >> n;

    int a[n];
    for(int i = 0 ;i < n ; i++)     cin >> a[i];

    vector<int> vec;
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        if(mp[a[i]] == 0)
        {
            mp[a[i]] = 1;
            vec.push_back(a[i]);
        }
    }

    cout << vec.size() << endl;
    for(int i = vec.size() - 1 ; i >= 0 ; i--)
    {
        cout << vec[i] << ends;
    }

    return 0;
}