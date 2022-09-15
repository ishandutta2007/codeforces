#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[1010101];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",A+i);
	sort(A,A+N);
	long long int ans=0;
	for(int i=0;i<N;i++) ans+=1LL*A[i]*(i+2);
	ans-=A[N-1];
	printf("%lld",ans);
}