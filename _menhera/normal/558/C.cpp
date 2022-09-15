#include<cstdio>
#include<set>
using namespace std;
int N;
int arr[101010];
int step(int a,int b)
{
	int cnt=0;
	while(a!=b)
	{
		if(a<b)
			b/=2;
		else
			a/=2;
		cnt++;
	}
	return cnt;
}
int main()
{
	scanf("%d",&N);
	set<int> S;
	for(int i=0;i<N;i++) scanf("%d",arr+i);
	for(int i=0;i<N;i++) S.insert(arr[i]);
	while(*S.begin()!=*S.rbegin())
	{
		int maxv=*S.rbegin();
		S.erase(S.find(maxv));
		S.insert(maxv/2);
	}
	int tv=*S.begin();
	int ret=987654321;
	for(int x=tv;x<101010;x*=2)
	{
		int ans=0;
		for(int i=0;i<N;i++)
			ans+=step(arr[i],x);
		ret=min(ret,ans);
	}
	printf("%d",ret);
}