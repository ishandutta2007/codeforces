#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> v(n+1,0);
	map<pair<int,int>,int> cnt;
	for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        v[a]++;
        v[b]++;
        if(cnt.find(make_pair(a,b))!=cnt.end()) cnt[make_pair(a,b)]++;
        else cnt.insert(make_pair(make_pair(a,b),1));
    }
    vector<pair<int,int> > d;
    for(int i=1;i<=n;i++) d.push_back(make_pair(v[i],i));
    sort(d.begin(),d.end(),greater<pair<int,int> >());
    bool res=0;
    for(int o=0;o<n;o++)
    {
        for(int i=o+1;i<n;i++)
        {
            if(d[o].first+d[i].first<m) break;
            if(d[o].first+d[i].first-cnt[make_pair(min(d[o].second,d[i].second),max(d[o].second,d[i].second))]>=m)
            {
                res=1;
                break;
            }
        }
        if(res) break;
    }
    if(res) printf("YES\n");
    else printf("NO\n");
	return 0;
}