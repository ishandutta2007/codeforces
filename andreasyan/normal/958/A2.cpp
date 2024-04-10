#include <bits/stdc++.h>
using namespace std;
const int N=2002,M=202,p=31;

int n,m;
char a[N][M];
char b[M][N];

map<long long,int> t;
int main()
{
    //freopen("dp.in","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<m;++i)
        cin>>b[i];
    for(int i=0;(i+m-1)<n;++i)
    {
        long long ast=1;
        long long ans=0;
        for(int j=i;j-i<m;++j)
        {
            for(int k=0;k<m;++k)
            {
                ans+=(ast*(a[j][k]-'a'));
                ast*=p;
            }
        }
        t[ans]=i;
    }
    for(int i=0;(i+m-1)<n;++i)
    {
        long long ast=1;
        long long ans=0;
        for(int j=0;j<m;++j)
        {
            for(int k=i;k-i<m;++k)
            {
                ans+=(ast*(b[j][k]-'a'));
                ast*=p;
            }
        }
        if(t.find(ans)!=t.end())
        {
            cout<<t[ans]+1<<' '<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}