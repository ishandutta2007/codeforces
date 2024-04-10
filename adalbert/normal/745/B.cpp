#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
string st[600];
///-----------------------------------------------------------------------///
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>st[i];
    }
    bool ch=0;
    int pi,pj,ki,kj;
    for (int i=1;i<=n;i++)
        for (int j=0;j<m;j++)
        {
            //cout<<ki<<' '<<kj<<'\n';
            if (st[i][j]=='X' && ch==0)
            {
                ch=1;
                pi=i;
                pj=j;
            }
            if (st[i][j]=='X')
            {
                ki=i;
                kj=j;
            }
        }
        //cout<<pi<<' '<<pj<<' '<<ki<<' '<<kj<<'\n';
        for (int i=pi;i<=ki;i++)
            for (int j=pj;j<=kj;j++)
            if (st[i][j]=='.')
            {
                cout<<"NO";
                return(0);
            }
        for (int i=1;i<=n;i++)
            for (int j=0;j<m;j++)
            if (st[i][j]=='X' && ((i<pi || i>ki) || (j<pj || j>kj)))
                        {
                cout<<"NO";
                return(0);
            }
        cout<<"YES";
}