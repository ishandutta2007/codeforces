#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100100];
int sum[100100];
pair<int, int> ans[100100];
int tp=0;
inline int count1(int L,int R) //inclusive
{
	return sum[R]-sum[L-1]-(R-L+1);
}
inline int count2(int L,int R)
{
	return 2*(R-L+1)-(sum[R]-sum[L-1]);
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",arr+i);
		sum[i]=sum[i-1]+arr[i];
	}
	for(int S=N;S>=1;S--)
	{
		int win1=0,win2=0,bs=0; // done till bs
		int lastwin=0;
		bool flag=true;
		while(bs!=N)
		{	
			//printf("%d %d\n",S,bs);
			int lo=bs; //nonend
			int hi=N; //end
			if(max(count1(bs+1,N),count2(bs+1,N))<S)
			{
				flag=false;
				break;
			}// N is not ending
			while(lo+1!=hi)
			{
				int mi=(lo+hi)/2;
				if(max(count1(bs+1,mi),count2(bs+1,mi))<S) lo=mi;
				else hi=mi;
			}
			//printf("<%d %d>\n",count1(bs+1,hi),count2(bs+1,hi));
			if(count1(bs+1,hi)>count2(bs+1,hi) )
			{	win1++; lastwin=1;}
			else{ win2++; lastwin=2;}
			bs=hi;
		}
		//printf("<%d>\n",flag);
		//printf("%d %d\n",win1,win2);
		if(flag &&  ( (win1>win2 && lastwin==1) ||(win1<win2 && lastwin==2)) ) 
		{
			ans[tp]=make_pair(max(win1,win2),S);
			tp++;
		}
	}
	sort(ans,ans+tp);
	printf("%d\n",tp);
	for(int i=0;i<tp;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}