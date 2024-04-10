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
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int main()
{
    int n,m;
    cin >> n >> m;

    string s[n];
    string s2[m];
    int ans=0 , ans2=0;

    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        bool b=true;
        for(int j=0;j<m;j++)
        {
            s2[j]+=s[i][j];
            if(s[i][j]!='.')
            {
                b=false;
            }
        }
        if(b)
        {
            ans++;
        }
    }

    for(int i=0;i<m;i++)
    {
        bool b=true;
        for(int j=0;j<n;j++)
        {
            if(s2[i][j]!='.')
            {
                b=false;
            }
        }
        if(b)
        {
            ans2++;
        }
    }

    cout << (ans*m)+(ans2*(n-ans)) << endl;

    return 0;
}