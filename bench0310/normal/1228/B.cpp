#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h,w;
	scanf("%d%d",&h,&w);
	int a[h+1][w+1];
	for(int o=0;o<=h;o++) for(int i=0;i<=w;i++) a[o][i]=-1;
	bool b=1;
	for(int o=0;o<h;o++)
    {
        int r;
        scanf("%d",&r);
        for(int i=0;i<r;i++)
        {
            if(a[o][i]==0) b=0;
            a[o][i]=1;
        }
        if(a[o][r]==1) b=0;
        a[o][r]=0;
    }
    for(int i=0;i<w;i++)
    {
        int c;
        scanf("%d",&c);
        for(int o=0;o<c;o++)
        {
            if(a[o][i]==0) b=0;
            a[o][i]=1;
        }
        if(a[c][i]==1) b=0;
        a[c][i]=0;
    }
    long long res=b;
    long long mod=1000000007;
    for(int o=0;o<h;o++) for(int i=0;i<w;i++) if(a[o][i]==-1) res=(2ll*res)%mod;
    printf("%I64d\n",res);
	return 0;
}