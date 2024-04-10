#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n/2;i++)
    {
        for (int j=1;j<=m;j++)
        {
            //cout<<i<<" "<<j<<endl;
            printf("%d",i);
            printf(" ");
            printf("%d\n",j);
            //cout<<(n-i+1)<<" "<<(m-j+1)<<endl;
            printf("%d",n-i+1);
            printf(" ");
            printf("%d\n",m-j+1);
        }
    }
    if (n&1)
    {
        int i=n/2+1;
        for (int j=1;j<=m/2;j++)
        {
            //cout<<i<<" "<<j<<endl;
            printf("%d",i);
            printf(" ");
            printf("%d\n",j);
            //cout<<i<<" "<<(m-j+1)<<endl;
            printf("%d",i);
            printf(" ");
            printf("%d\n",m-j+1);
        }
        if (m&1) cout<<i<<" "<<(m/2+1);
    }
    return 0;
}