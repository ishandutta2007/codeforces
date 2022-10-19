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

int main()
{
    int n , v;
    cin >> n >> v;

    vector<int> m(n,1e7);
    for(int i=0;i<n;i++)
    {
        int k;
        cin >> k;
        for(int j=0;j<k;j++)
        {
            int t;
            cin >> t;
            m[i]=min(m[i],t);
        }
    }

    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(m[i]<v)
        {
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    for(auto i:ans)
    {
        cout << i << ends;
    }

    return 0;
}