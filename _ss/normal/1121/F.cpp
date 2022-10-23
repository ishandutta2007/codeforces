#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=6e3+1,inf=5e7;
int n,a,b,f[maxn],z[maxn],t[maxn];
char s[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    //cout<<5000<<" "<<5000<<" "<<100<<endl;
    //for (int i=1;i<=5000;i++) cout<<"v";
    cin>>n>>a>>b;
    char ch=getchar();
    for (int i=n;i>=1;i--) s[i]=getchar();
    int l,r;
    for (int i=1;i<n;i++)
    {
        for (int j=i;j<=n;j++) z[j]=0;
        l=i;r=i;
        for (int j=i+1;j<=n;j++)
        {
            if (j<=r) z[j]=min(r-j+1,z[j-l+i]);
            else
            {
                l=j;
                r=j;
            }
            for (;j+z[j]<=n && s[j+z[j]]==s[z[j]+i];) z[j]++;
            if (j+z[j]-1>r)
            {
                r=j+z[j]-1;
                l=j;
            }
        }
        for (int j=i+1;j<=n;j++) t[i]=max(t[i],min(i-1+z[j],j-1));
    }
    for (int i=1;i<=n;i++) f[i]=inf;
    f[n]=a;
    for (int i=n-1;i>=1;i--)
    {
        f[i]=min(a+f[i+1],b+f[t[i]+1]);
        //for (int j=i;j<=t[i];j++) f[i]=min(f[i],b+f[j+1]);
    }
    cout<<f[1];
    //for (int i=1;i<=n;i++) cout<<t[i]<<" ";
    return 0;
}