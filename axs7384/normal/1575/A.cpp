#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s[N];
int rk[N];
int n,m;
bool cmp(int x,int y)
{
    return s[x]<s[y];
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>s[i];
        for (int j=1;j<m;j+=2)
            s[i][j]='a'+('z'-s[i][j]);
    }
    for (int i=1;i<=n;++i)
        rk[i]=i;
    sort(rk+1,rk+1+n,cmp);
    for (int i=1;i<=n;++i)
        printf("%d ",rk[i]);
    puts("");
    return 0;
}