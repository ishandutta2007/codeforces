#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int p[n];
	int idx=0;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        if(p[i]==m) idx=i;
    }
    map<int,int> l,r;
    l.insert({0,1});
    r.insert({0,1});
    int d=0;
    for(int i=idx-1;i>=0;i--)
    {
        if(p[i]>m) d++;
        else d--;
        if(l.find(d)!=l.end()) l[d]++;
        else l.insert({d,1});
    }
    d=0;
    for(int i=idx+1;i<n;i++)
    {
        if(p[i]>m) d++;
        else d--;
        if(r.find(d)!=r.end()) r[d]++;
        else r.insert({d,1});
    }
    long long res=0;
    for(pair<int,int> p:l)
    {
        for(int i=0;i<=1;i++)
        {
            if(r.find(i-p.first)!=r.end()) res+=((long long)p.second*r[i-p.first]);
        }
    }
    printf("%I64d\n",res);
	return 0;
}