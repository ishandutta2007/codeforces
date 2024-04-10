#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n][m];
	int b[n][m];
	for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a[o][i]);
            b[o][i]=0;
        }
    }
    vector<pair<int,int>> v;
    for(int o=0;o<n-1;o++)
    {
        for(int i=0;i<m-1;i++)
        {
            if(a[o][i]==1&&a[o+1][i]==1&&a[o][i+1]==1&&a[o+1][i+1]==1)
            {
                v.push_back({o+1,i+1});
                b[o][i]=b[o+1][i]=b[o][i+1]=b[o+1][i+1]=1;
            }
        }
    }
    bool ok=1;
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            if(a[o][i]!=b[o][i]) ok=0;
        }
    }
    if(ok)
    {
        printf("%d\n",(int)v.size());
        for(pair<int,int> p:v) printf("%d %d\n",p.first,p.second);
    }
    else printf("-1\n");
	return 0;
}