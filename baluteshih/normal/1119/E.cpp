#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll arr[300005];
map<ll,ll> s;
priority_queue<ll> single;

int main()
{jizz
	ll n,x,ans=0;
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> arr[i];
		if(arr[i]&1) single.push(i);
		if(arr[i]>1) s[i]=arr[i]/2*2;
	}
	if(s.empty())
		return cout << 0 << "\n",0;
	for(auto p=--s.end();!s.empty();)
	{
		while(p->S>0)
		{
			if(single.size())
			{
				while(!single.empty()&&p->S)
				{
					x=single.top(),single.pop();
					arr[x]^=1;
					if(x>p->F) continue;
					p->S-=2,++ans;
				}
			}
			else if(s.size()==1)
			{
				if(arr[p->F]&1) ans+=(p->S+1)/3,arr[p->F]^=1;
				else ans+=p->S/3;
				break;
			}
			else
			{
				auto q=s.begin();
				if(q->S*2>=p->S)
				{
					q->S-=p->S/2,ans+=p->S/2,p->S=0;
					if(q->S&1)
						arr[q->F]|=1,--q->S,single.push(q->F);
					if(!q->S) s.erase(q);
				}
				else
					ans+=q->S,p->S-=q->S*2,s.erase(q);
			}
		}
		s.erase(p--);
	}
	cout << ans << "\n";
	
}