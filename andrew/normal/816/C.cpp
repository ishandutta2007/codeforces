#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
using namespace std;
vector <ll> tt[1000];
string s[1000000],ss[1000000];
char c1,c2,c3,c4;
ll mn,n,m,j,i,k,kk,sc,a[1000][1000],b[1000000],q[1000][1000],bb[1000000];
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(i=0;i<n;i++)for(j=0;j<m;j++){cin >> a[i][j];q[i][j]=a[i][j];}
    for(i=0;i<n;i++)
    {
        mn=1e18;
        for(j=0;j<m;j++)mn=min(mn,a[i][j]);
        if(mn!=0)
        {
            for(j=0;j<m;j++)a[i][j]-=mn;
            ll x=k+mn;
            for(j=k;j<x;j++)
            {
                k++;
                s[k]="row ";
                b[k]=i;
            }
        }
    }
   // if(n==100 and m==99)cout << kk << " " << k << endl;
    for(i=0;i<m;i++)
    {
        mn=1e18;
        for(j=0;j<n;j++)mn=min(mn,a[j][i]);
        if(mn!=0)
        {
            for(j=0;j<n;j++)a[j][i]-=mn;
            ll x=k+mn;
            for(j=k;j<x;j++)
            {
                k++;
                s[k]="col ";
                b[k]=i;
            }
        }
    }

    for(i=0;i<n;i++)for(j=0;j<m;j++)if(a[i][j]!=0)k=1e18;

        //if(n==100 and m==99)cout << kk << " " << k << endl;
    for(i=0;i<n;i++)for(j=0;j<m;j++)a[i][j]=q[i][j];
            //if(n==100 and m==99)cout << kk << " " << k << endl;
    for(i=0;i<m;i++)
    {
        mn=1e18;
        for(j=0;j<n;j++)mn=min(mn,a[j][i]);
        if(mn!=0)
        {
            for(j=0;j<n;j++)a[j][i]-=mn;
            ll x=kk+mn;
            for(j=kk;j<x;j++)
            {
                kk++;
                ss[kk]="col ";
                bb[kk]=i;
            }
        }
    }
           // if(n==100 and m==99)cout << kk << " " << k << endl;
    //cout << a[1 ][0] << endl;
    for(i=0;i<n;i++)
    {
        mn=1e18;
        for(j=0;j<m;j++)mn=min(mn,a[i][j]);
      //  cout << mn << endl;
        if(mn!=0)
        {
            for(j=0;j<m;j++)a[i][j]-=mn;
            ll x=kk+mn;
            for(j=kk;j<x;j++)
            {
                kk++;
                ss[kk]="row ";
                bb[kk]=i;
            }
        }
    }
          //  if(n==100 and m==99)cout << kk << " " << k << endl;
          //  if(n==100 and m==99)cout << kk << " " << k << endl;
   // cout << kk << endl;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(a[i][j]!=0)kk=1e18;
    if(k==kk and kk==1e18)
    {
        cout << -1 << endl;
        return 0;
    }
    if(kk<k)
    {
      cout << kk << endl;
    for(i=1;i<=kk;i++)cout << ss[i] << " " << bb[i]+1 << endl;

    }else
    {

    cout << k << endl;
    for(i=1;i<=k;i++)cout << s[i] << " " << b[i]+1 << endl;
    }
    return 0;
}