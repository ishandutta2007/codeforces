#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<pair<int,int> > s(n),t(n),d(n);
	for(int i=0;i<n;i++) scanf("%d",&s[i].first);
	for(int i=0;i<n;i++) scanf("%d",&t[i].first);
	for(int i=0;i<n;i++) s[i].second=i;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	for(int i=0;i<n;i++) d[i]=make_pair(t[i].first-s[i].first,s[i].second);
	long long sum=0;
	for(int i=0;i<n;i++)
    {
        sum+=(long long)d[i].first;
        if(sum<0) return 3-printf("NO\n");
    }
    if(sum!=0) return 3-printf("NO\n");
    stack<pair<int,int> > a;
    vector<pair<int,int> > res;
    vector<int> dist;
    for(int i=0;i<n;i++)
    {
        if(d[i].first>0) a.push(make_pair(d[i].first,d[i].second));
        if(d[i].first<0)
        {
            d[i].first=-d[i].first;
            while(d[i].first>0)
            {
                pair<int,int> p=a.top();
                a.pop();
                res.push_back(make_pair(p.second,d[i].second));
                if(d[i].first>=p.first)
                {
                    d[i].first-=p.first;
                    dist.push_back(p.first);
                }
                else
                {
                    p.first-=d[i].first;
                    dist.push_back(d[i].first);
                    d[i].first=0;
                    a.push(p);
                }
            }
        }
    }
    printf("YES\n");
    printf("%d\n",res.size());
    for(int i=0;i<(int)res.size();i++) printf("%d %d %d\n",res[i].first+1,res[i].second+1,dist[i]);
	return 0;
}