#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

int gcd(int a,int b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<n-1)
    {
        printf("Impossible\n");
        return 0;
    }
	vector<pair<int,int>> v;
    for(int o=1;o<=n;o++)
    {
        for(int i=o+1;i<=n;i++)
        {
            if(gcd(o,i)==1) v.push_back({o,i});
            if((int)v.size()==m) break;
        }
        if((int)v.size()==m) break;
    }
    if((int)v.size()>=m)
    {
        printf("Possible\n");
        for(int i=0;i<m;i++) printf("%d %d\n",v[i].first,v[i].second);
    }
    else printf("Impossible\n");
	return 0;
}