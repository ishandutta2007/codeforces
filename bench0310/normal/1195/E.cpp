#include <bits/stdc++.h>

using namespace std;

deque<long long> q;

void in(long long a)
{
    while(!q.empty()&&q.back()>a) q.pop_back();
    q.push_back(a);
}

void out(long long a)
{
    if(!q.empty()&&q.front()==a) q.pop_front();
}

long long query()
{
    return q.front();
}

int main()
{
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	long long g,x,y,z;
	scanf("%I64d%I64d%I64d%I64d",&g,&x,&y,&z);
	long long h[n][m];
	h[0][0]=g;
	for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            if(o==0&&i==0) continue;
            g=(g*x+y)%z;
            h[o][i]=g;
        }
    }
    long long d[n][m];
    for(int i=0;i<m;i++)
    {
        for(int o=0;o<a;o++) in(h[o][i]);
        d[0][i]=query();
        for(int o=a;o<n;o++)
        {
            out(h[o-a][i]);
            in(h[o][i]);
            d[o-a+1][i]=query();
        }
        q.clear();
    }
    long long res[n][m];
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<b;i++) in(d[o][i]);
        res[o][0]=query();
        for(int i=b;i<m;i++)
        {
            out(d[o][i-b]);
            in(d[o][i]);
            res[o][i-b+1]=query();
        }
        q.clear();
    }
    long long cnt=0;
    for(int o=0;o+a-1<n;o++)
    {
        for(int i=0;i+b-1<m;i++)
        {
            cnt+=res[o][i];
        }
    }
    printf("%I64d\n",cnt);
	return 0;
}