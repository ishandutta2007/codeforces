#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p;

long long greater_count(int m)
{
    vector<int> x(n,0);
    for(int i=0;i<n;i++)
    {
        if(p[i]>=m) x[i]=1;
        else x[i]=-1;
    }
    vector<int> sum(2*n+1,0);
    sum[n]=1;
    int now=n;
    int cnt=0;
    long long res=0;
    for(int i=0;i<n;i++)
    {
        now+=x[i];
        if(x[i]==1) cnt+=sum[now-1];
        else cnt-=sum[now];
        res+=(long long)cnt;
        sum[now]++;
    }
    return res;
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	p.resize(n);
	for(int i=0;i<n;i++) scanf("%d",&p[i]);
	printf("%I64d\n",greater_count(m)-greater_count(m+1));
	return 0;
}