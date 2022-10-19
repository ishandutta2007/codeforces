#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int i;
        int m=n/2;
        for(i=1;i<=n;i++)if(s[i]=='0')break;
        if(i==n+1)cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<endl;
        else if(i<=m)cout<<i<<" "<<n<<" "<<i+1<<" "<<n<<endl;
        else cout<<1<<" "<<i<<" "<<1<<" "<<i-1<<endl;
    }
    return 0;
}