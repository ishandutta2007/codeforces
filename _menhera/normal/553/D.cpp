#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int N,M,K;
vector<int> conn[101010];
vector<int> pt;
bool unusable[101010];
bool used[101010];
bool aused[101010];
struct frac{
	int u;
	int d;
};
	inline bool operator< (const frac& lhs, const frac& rhs)
	{
		return 1LL*lhs.u*rhs.d<1LL*lhs.d*rhs.u;
	}
	inline bool operator> (const frac& lhs, const frac& rhs)
	{
		return rhs<lhs;
	}
	inline bool operator<= (const frac& lhs, const frac& rhs)
	{
		return !(lhs > rhs);
	}
	inline bool operator>= (const frac& lhs, const frac& rhs)
	{
		return !(lhs < rhs);
	}
frac now[101010];
frac anow[101010];
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<K;i++)
	{
		int t;
		scanf("%d",&t);
		unusable[t-1]=true;
	}
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	for(int i=0;i<N;i++)
		if(!unusable[i])
		{
			pt.push_back(i);
			aused[i]=used[i]=true;
		}
	set<pair<frac,int> >yowane;
	set<pair<frac,int> >ayowane;
	for(int i=0;i<pt.size();i++)
	{
		frac tmp;
		tmp.u=0; tmp.d=0;
		for(int j=0;j<conn[pt[i]].size();j++)
		{
			tmp.d++;
			if(used[conn[pt[i]][j]]) tmp.u++;
		}
		yowane.insert(make_pair(tmp,pt[i]));
		ayowane.insert(make_pair(tmp,pt[i]));
		now[pt[i]]=tmp;
		anow[pt[i]]=tmp;
	}
	frac coushin;
	int cnt=0;
	coushin.u=-1; coushin.d=1;
	while(!yowane.empty())
	{
		set<pair<frac,int> >::iterator it=yowane.begin();
		if(coushin<(*it).first)
		{
			coushin=(*it).first;
			cnt=yowane.size();
		}
		int no=(*it).second;
		//printf("%d ",no);
		yowane.erase(it);
		used[no]=false;
		now[no].u=0;
		now[no].d=0;
		for(int i=0;i<conn[no].size();i++)
		{
			int target=conn[no][i];
			if(!used[target]) continue;
			yowane.erase(make_pair(now[target],target));
			now[target].u--;
			yowane.insert(make_pair(now[target],target));
		}
	}
	//printf("%d",cnt)
	while(!ayowane.empty())
	{
		if(cnt==ayowane.size())
		{
			printf("%d\n",cnt);
			for(set<pair<frac,int> >::iterator it=ayowane.begin();it!=ayowane.end();it++)
				printf("%d ",(*it).second+1);
			return 0;
		}
		set<pair<frac,int> >::iterator it=ayowane.begin();
		int no=(*it).second;
		ayowane.erase(it);
		aused[no]=false;
		for(int i=0;i<conn[no].size();i++)
		{
			int target=conn[no][i];
			if(!aused[target]) continue;
			ayowane.erase(make_pair(anow[target],target));
			anow[target].u--;
			ayowane.insert(make_pair(anow[target],target));
		}
	}
}