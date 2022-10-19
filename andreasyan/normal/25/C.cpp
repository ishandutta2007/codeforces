#include <bits/stdc++.h>
using namespace std;
const int N=303;

int n;

long long a[N][N];
void ubd_a(int k)
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
}

long long sum;
void ubd_sum()
{
    sum=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<i;++j)
            sum+=a[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    ubd_sum();
    int q;
    cin>>q;
    while(q--)
    {
        int x,y,d;
        cin>>x>>y>>d;
        if(a[x][y]<=d)
            cout<<sum<<endl;
        else
        {
            a[x][y]=d;
            a[y][x]=d;
            ubd_a(x);
            ubd_a(y);
            ubd_sum();
            cout<<sum<<endl;
        }
    }
    return 0;
}