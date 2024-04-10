#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
int H;
long long Q;
vector<pair<long long int,long long int> > no;
vector<long long int> yesl,yesr;
void cheat()
{
	puts("Game cheated!");
	exit(0);
}
int main()
{
	scanf("%d%lld",&H,&Q);
	for(int x=0;x<Q;x++)
	{
		int i;
		long long L,R;
		int ans;
		scanf("%d%lld%lld%d",&i,&L,&R,&ans);
		L-=(1LL<<(i-1));
		R-=(1LL<<(i-1));
		R++;
		L<<=(H-i);
		R<<=(H-i);
		//printf("%lld %lld\n",L,R);
		if(ans==1)
		{
			yesl.push_back(L);
			yesr.push_back(R);
		}else
		{
			no.emplace_back(L,-1);
			no.emplace_back(R,1);
		}
	}
	long long int rangeL=0;
	long long int rangeR=1LL<<(H-1);
	if(yesl.size()!=0)
	{
	rangeL=*max_element(yesl.begin(),yesl.end());
	rangeR=*min_element(yesr.begin(),yesr.end());
	}
	no.emplace_back(0,-1);
	no.emplace_back(rangeL,1);
		no.emplace_back(rangeR,-1);
		no.emplace_back(1LL<<(H-1),1);
	if(rangeL>=rangeR)
		cheat();
	sort(no.begin(),no.end());
	int dupe=0;
	long long int now=0;
	long long int rangelength=0;
	long long int ans=0;
	for(int i=0;i<no.size();i++)
	{
		long long int prev=now;
		now=no[i].first;
		switch(no[i].second)
		{
		case -1:
			dupe++;
			if(dupe==1)
			{
				//printf("[%lld,%lld)\n",prev,now);
				rangelength+=now-prev;
				if(now!=prev) ans=prev;
			}
			break;
		case 1:
			dupe--;
			break;
		}
	}
	if(rangelength==0) cheat();
	if(rangelength==1)
		printf("%lld\n",ans+(1LL<<(H-1)));
	else
		puts("Data not sufficient!");
	return 0;
}