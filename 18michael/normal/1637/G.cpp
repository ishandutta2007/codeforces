#include<bits/stdc++.h>
#define Mx 50000
using namespace std;
int Test_num,mx;
int to[50002];
vector<int> vec;
typedef pair<int,int> P;
vector<P> ans;
inline void solve(int x,int y)
{
	if(!x)return ;
	if(x==to[x])
	{
		vec.push_back(to[x]<<y),solve(x-1,y);
		return ;
	}
	for(int i=(to[x]>>1)+1;i<=x;++i)ans.push_back(P((i<<y),((to[x]-i)<<y))),vec.push_back(to[x]<<y);
	vec.push_back((to[x]>>1)<<y),solve(to[x]-x-1,y),solve(x-(to[x]>>1),y+1);
}
int main()
{
	scanf("%d",&Test_num),to[1]=1;
	for(int i=2;i<=Mx;++i)if((to[i]=to[i-1])<i)to[i]<<=1;
	for(int x;Test_num--;)
	{
		scanf("%d",&x);
		if(x==2)puts("-1");
		else
		{
			vec.clear(),ans.clear(),solve(x,0),sort(vec.begin(),vec.end()),mx=vec.back();
			for(int i=0;i<vec.size();++i)
				if(vec[i]==vec[i+1])
				{
					ans.push_back(P(vec[i],vec[i+1])),vec[i]=0;
					if((vec[i+1]<<=1)>mx)mx=vec[i+1];
					break;
				}
			for(int i=0;i<vec.size();++i)if(vec[i])while(vec[i]<mx)ans.push_back(P(0,vec[i])),ans.push_back(P(vec[i],vec[i])),vec[i]<<=1;
			ans.push_back(P(0,mx)),printf("%d\n",ans.size());
			for(int i=0;i<ans.size();++i)printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
	return 0;
}