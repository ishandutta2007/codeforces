#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
///-----------------------------------------------------------------------///
string st1,st2;
vector <ll> res,vec[100];
ll cnt[1000];
ll a[100][100];
///-----------------------------------------------------------------------///
int main()
{
    ll n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>a[i][j];
    bool check=1;
      for (int i=1;i<=n;i++)

        {
            ll k=0;
            for (int j=1;j<=m;j++)
                if (a[i][j]!=j) k++;
            if (k>2) check=0;
        }
    if (check)
            {
                cout<<"YES";
                return(0);
            }
    for (int f=1;f<=m-1;f++)
        for (int l=f+1;l<=m;l++)
        {
            check=1;

            for (int i=1;i<=n;i++)
            {
                ll k=0;
                for (int j=1;j<=m;j++)
                    if (j!=f && j!=l)
                    {
                        if (a[i][j]!=j) k++;
                    } else
                    {
                        if (j==f && a[i][j]!=l) k++;
                        if (j==l && a[i][j]!=f) k++;
                    }
                if (k>2) check=0;
            }
            //cout<<f<<' '<<l<<' '<<check<<'\n';
            if (check)
            {
                cout<<"YES";
                return(0);
            }
        }
    cout<<"NO";
}