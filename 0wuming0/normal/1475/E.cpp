#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[1004];
int mod=1e9+7;
int cmp(int x,int y)
{
    return x>y;
}
ll C[2005][2005];
int main()
{
    int t;
    for(int i=0;i<2005;i++)
    {
        C[i][i]=C[i][0]=1;
    }
    for(int i=2;i<2005;i++)for(int j=1;j<i;j++)
    {
        C[i][j]=C[i-1][j]+C[i-1][j-1];
        C[i][j]%=mod;
    }
    //cout<<C[5][3]<<endl;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        sort(a,a+n,cmp);
        int b=0;
        for(int i=0;i<k-1;i++)
        {
            if(a[k-1]!=a[i])b++;
        }
        int c=0;
        for(int i=k;i<n;i++)
        {
            if(a[k-1]==a[i])c++;
        }
        k-=b;
        c+=k;
        cout<<C[c][k]<<endl;
    }
    return 0;
}