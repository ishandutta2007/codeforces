#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	vector<pair<int,int>> pos,neg;
	for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a=max(a,-b);
        if(b>=0) pos.push_back({a,b});
        else neg.push_back({a,b});
    }
    bool res=1;
    sort(pos.begin(),pos.end());
    for(pair<int,int> p:pos)
    {
        if(r<p.first) res=0;
        r+=p.second;
    }
    sort(neg.begin(),neg.end(),[](pair<int,int> a,pair<int,int> b){return a.first+a.second>b.first+b.second;});
    for(pair<int,int> p:neg)
    {
        if(r<p.first) res=0;
        r+=p.second;
    }
    if(res) printf("YES\n");
    else printf("NO\n");
	return 0;
}