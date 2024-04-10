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

int main()
{
    int n , r=0 , u=0 , ans=0;
    bool sr=true , su=true;
    string s;
    cin >> n >> s;

    int p=-1;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
        {
            r++;
        }
        else
        {
            u++;
        }
        int t=(r>u?1:0);
        if(t!=p && r!=u && p!=-1)
        {
            ans++;
        }
        p=(r!=u?t:p);
    }

    cout << ans << endl;
    return 0;
}