#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
typedef pair<long long,long long> frac;
using namespace std;
struct line{
	int A,B,C;
}lines[101010];
inline void stopnow()
{
	if((double)clock()/CLOCKS_PER_SEC>1.9)
	{
		puts("NO");
		exit(0);
	}
}
inline int randint(int N)
{
	return (unsigned int)((rand()&0x0000ffff)+(rand()<<16))%N;
}
inline bool par(line &L1,line &L2)
{
	return 1LL*L1.A*L2.B==1LL*L2.A*L1.B;
}
inline pair<frac,frac> intersect(line &L1,line &L2)
{
	long long y=1LL*L1.A*L2.C-1LL*L2.A*L1.C;
	long long x=1LL*L1.C*L2.B-1LL*L2.C*L1.B;
	long long b=1LL*L1.B*L2.A-1LL*L2.B*L1.A;
	return make_pair(make_pair(y,b),make_pair(x,b));
}
inline bool online(line &L1,pair<frac,frac> P)
{
	long long y=P.first.first;
	long long x=P.second.first;
	long long b=P.first.second;
	return L1.A*x+L1.B*y+L1.C*b==0;
}
bool used[101010];
int tp=0;
int ans[5][2];
int N,K;
void calc(int A)
{
	stopnow();
	vector<int> arr;
	for(int i=0;i<N;i++) if(!used[i]) arr.push_back(i);
	int c=arr.size();
	if(c<=A)
	{
		puts("YES");
		printf("%d\n",tp+c);
		for(int i=0;i<tp;i++)
			printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
		for(int i=0;i<c;i++)
				printf("%d %d\n",arr[i]+1,-1);
		exit(0);
	}
	if(A==1)
	{
		//c>=2
		if( par(lines[arr[0]],lines[arr[1]]) ) return;
		auto x=intersect(lines[arr[0]],lines[arr[1]]);
		for(int i=2;i<c;i++)
			if(!online(lines[arr[i]],x)) return;
		puts("YES");
		printf("%d\n",tp+1);
		for(int i=0;i<tp;i++)
			printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
		printf("%d %d\n",arr[0]+1,arr[1]+1);
		exit(0);
	}
	int itcount;
	
	if(A==K)
		itcount=1e9;
	else
		itcount=A*A*5;
	while(itcount--)
	{
		stopnow();
		int limit=(c-K+1)/K; // over or equal than limit
		int X1=randint(c);
		int X2=randint(c);
		if(par(lines[arr[X1]],lines[arr[X2]])) continue;
		auto ddd=intersect(lines[arr[X1]],lines[arr[X2]]);
		for(int i=0;i<c;i++)
		{
			if(online(lines[arr[i]],ddd))
			{
				limit--;
				used[arr[i]]=true;
			}
		}
		if(limit<=0)
		{
			ans[tp][0]=arr[X1];
			ans[tp][1]=arr[X2];
			tp++;
			calc(A-1);
			tp--;
		}
		for(int i=0;i<c;i++)
			used[arr[i]]=false;
	}
	return;
}
int main()
{
	srand(time(NULL));
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%d%d%d",&lines[i].A,&lines[i].B,&lines[i].C);
	calc(K);
	puts("NO");
}