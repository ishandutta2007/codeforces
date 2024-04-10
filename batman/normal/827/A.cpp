#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)
#define K ((ll)1001*1000)
#define INF ((ll)2e9)

ll n,len;
string s[N];
vector <pair<ll,ll> > v;
char inp[K];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll ex;
		scanf("%s",inp);s[i]=inp;
		scanf("%d",&ex);
		for(int j=0;j<ex;j++)
		{
			ll x;
			scanf("%d",&x);x--;
			v.push_back({x,i});
			len=max(len,x+(ll)s[i].size());
		}
	}
	sort(v.begin(),v.end());
	ll now_id=-1,now_pos=-1;
	for(int i=0,j=0;i<len;i++)
	{
		if(now_id!=-1 && now_pos==s[now_id].size())now_id=-1,now_pos=-1;
		while(j<v.size() && v[j].first==i)
		{
//			cout<<j<<" "<<v[j].first<<" "<<v[j].second<<"|| \n";
			if(now_id==-1)
			{
				now_id=v[j].second;now_pos=0;
				j++;
				continue;
			}
			ll rem=(ll)s[now_id].size()-now_pos;
			if(rem<s[v[j].second].size())
			{
				now_id=v[j].second;now_pos=0;
			}
			j++;
		}
//		cout<<now_id<<" "<<now_pos<<"\n";
		if(now_id==-1)printf("a");
		else printf("%c",s[now_id][now_pos]);
		now_pos++;
	}
	return 0;
}