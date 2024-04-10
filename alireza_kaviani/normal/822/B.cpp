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

    int n , m , sz = 1e9;
    string s , t;
    cin >> n >> m >> s >> t;

    vector<int> ans;
    for(int i = 0 ; i <= m - n ; i++)
    {
        vector<int> dif;
        string k = t.substr(i , n);
        for(int j = 0 ;j < n ; j++)
        {
            if(s[j] != k[j])
            {
                dif.push_back(j + 1);
            }
        }

        if(dif.size() < sz)
        {
            sz = dif.size();
            ans = dif;
        }
    }

    cout << ans.size() << endl;
    for(int i : ans)
    {
        cout << i << ends;
    }

    return 0;
}