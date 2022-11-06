#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=5010;
char s[V][V];
int r[V][V],n,m;
int cnt[V],sum[V];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        scanf("%s",s[i]);
        for(int i=0;i<n;i++)
        {
            r[i][m]=0;
            for(int j=m-1;j>=0;j--)
            if(s[i][j]=='1')r[i][j]=r[i][j+1]+1;
            else r[i][j]=0;
        }
        int ret=0;
        for(int i=0;i<m;i++)
        {
            memset(cnt,0,sizeof(cnt));
            for(int j=0;j<n;j++)
            cnt[r[j][i]]++;
            sum[m+1]=0;
            for(int j=m;j>=0;j--)
            sum[j]=sum[j+1]+cnt[j];
            for(int j=m;j>=0;j--)
            ret=max(ret,j*sum[j]);
        }
        printf("%d\n",ret);
    }
}