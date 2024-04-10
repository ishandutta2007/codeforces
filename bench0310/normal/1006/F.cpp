#include <bits/stdc++.h>

using namespace std;

int n,m;
long long k;
long long a[20][20];
map<long long,long long> t[20][20];

bool in(int o,int i)
{
    return (0<=o&&o<n&&0<=i&&i<m);
}

void mv(int o,int i,int d)
{
    for(pair<long long,long long> p:t[o][i])
    {
        if(in(o+d,i)) t[o+d][i][p.first^a[o+d][i]]+=p.second;
        if(in(o,i+d)) t[o][i+d][p.first^a[o][i+d]]+=p.second;
    }
}

int main()
{
	scanf("%d%d%I64d",&n,&m,&k);
	for(int o=0;o<n;o++) for(int i=0;i<m;i++) scanf("%I64d",&a[o][i]);
	if(n==1&&m==1)
    {
        printf("%d\n",(a[0][0]==k));
        return 0;
    }
	int mid=(n+m-2)/2;
	t[0][0][a[0][0]]=1;
	for(int d=0;d<mid;d++)
    {
        for(int j=0;j<=d;j++)
        {
            if(in(j,d-j)) mv(j,d-j,1);
        }
    }
    t[n-1][m-1][a[n-1][m-1]]=1;
    for(int d=0;mid+d<=n+m-4;d++)
    {
        for(int j=0;j<=d;j++)
        {
            if(in(n-1-j,m-1-(d-j))) mv(n-1-j,m-1-(d-j),-1);
        }
    }
    long long res=0;
    for(int j=0;j<=mid;j++)
    {
        if(in(j,mid-j))
        {
            for(pair<long long,long long> p:t[j][mid-j])
            {
                if(in(j+1,mid-j)&&t[j+1][mid-j].find(p.first^k)!=t[j+1][mid-j].end())
                {
                    res+=p.second*t[j+1][mid-j][p.first^k];
                }
                if(in(j,mid-j+1)&&t[j][mid-j+1].find(p.first^k)!=t[j][mid-j+1].end())
                {
                    res+=p.second*t[j][mid-j+1][p.first^k];
                }
            }
        }
    }
    printf("%I64d\n",res);
	return 0;
}