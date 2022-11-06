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
const int V=100100;
const int P=1000000007;
int AB(int x){if(x<0)return -x;return x;}
int n,m,a[V];
vector<int> b[V];
int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)b[i].clear();
        for(int i=0;i<n;i++)
        {
            if(i>0&&a[i]!=a[i-1])b[a[i]].push_back(a[i-1]);
            if(i+1<n&&a[i]!=a[i+1])b[a[i]].push_back(a[i+1]);
        }
        LL ret=0;
        for(int i=1;i<n;i++)ret+=AB(a[i]-a[i-1]);
        LL mx=0;
        for(int i=1;i<=m;i++)
        {
            int sz=b[i].size();
            if(sz==0)continue;
            sort(b[i].begin(),b[i].end());
            LL tmp=0;
            for(int j=0;j<sz;j++)
            tmp+=AB(i-b[i][j]);
            for(int j=0;j<sz;j++)
            tmp-=AB(b[i][sz/2]-b[i][j]);
            mx=max(mx,tmp);
        }
        cout<<ret-mx<<endl;
    }
}