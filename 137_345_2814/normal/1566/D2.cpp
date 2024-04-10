#include<cstdio>
#include<algorithm>
using namespace std;
#define N 305
#define M 100500
int T,n,m,a;
pair<int,int> tp[M];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*m;i++)scanf("%d",&a),tp[i]=make_pair(a,i);
		sort(tp+1,tp+n*m+1);
		int as=0;
		for(int i=1;i<=n;i++)
		{
			int l=(i-1)*m+1,r=i*m;
			for(int j=l;j<=r;j++)
			for(int k=j+1;k<=r;k++)
			if(tp[j].first!=tp[k].first&&tp[j].second<tp[k].second)as++;
		}
		printf("%d\n",as);
	}
}