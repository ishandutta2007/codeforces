#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200500
int T,n,ct,le[N];
char s[N];
int solve()
{
	int ls=1;ct=0;
	for(int i=2;i<=n;i++)if(s[i]!=s[i-1])le[++ct]=ls,ls=1;else ls++;
	le[++ct]=ls;
	int res=0,tp=0;
	for(int i=1;i<=ct;i++)res+=le[i]-1;
	for(int i=1;i<=ct;i++)
	{
		if(!res)return i-1+(ct-i+2)/2;
		res--;tp++;
		int s1=min(le[i]-1,tp);tp-=s1;le[i]-=s1;
		res-=le[i]-1;
	}
	return ct;
}
int main()
{
	scanf("%d",&T);
	while(T--)scanf("%d%s",&n,s+1),printf("%d\n",solve());
}