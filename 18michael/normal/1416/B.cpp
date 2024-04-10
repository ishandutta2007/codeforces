#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,v,d,Test_num,sum;
int a[100002];
typedef pair<int,int> P;P p;
priority_queue<P,vector<P>,greater<P> > pq;
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d",&n),sum=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum+=a[i];
		if(sum%n){puts("-1");continue;}printf("%d\n",3*(n-1)),sum/=n;
		for(int i=2;i<=n;++i)a[i]-=sum,pq.push(P(((i-((sum+a[i])%i))%i),i));
		while(!pq.empty())p=pq.top(),pq.pop(),v=p.second,d=p.first,printf("%d %d %d\n%d %d %d\n",1,v,d,v,1,(a[v]+d+sum)/v);
		for(int i=2;i<=n;++i)printf("1 %d %d\n",i,sum);
	}
	return 0;
}