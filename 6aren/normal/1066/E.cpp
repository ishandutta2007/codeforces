#include <bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
long long n,m,x[200005],y[200005];
long long dapso;

int main()
{
    long long temp,cnt;
    cin >> n >> m;
    cin >> a >> b;
    for (int i=1;i<=n;i++)
    {
        x[i]=(long long) a[i-1]-48;
    }
    for (int i=1;i<=m;i++)
    {
        temp=(long long) b[i-1]-48;
        y[i]=y[i-1]+temp;
    }
    temp=1;
    for (long long i=n;i>=1;i--)
    {
        long long u=max(m-n+i,0LL);
        dapso+=x[i]*y[u]*temp;
        dapso=dapso%998244353;
        temp=temp*2;
        temp=temp%998244353;
    }
    cout << dapso;
}