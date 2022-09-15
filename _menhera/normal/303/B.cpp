#include<algorithm>
#include<cstdio>
using namespace std;
long long N,M,X,Y,A,B;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&N,&M,&X,&Y,&A,&B);
	long long g=__gcd(A,B);
	A/=g,B/=g;
	long long maxmult=min(N/A,M/B);
	long long W=maxmult*A,H=maxmult*B;
	X=2*X-W;
	if(X<0) X=0;
	if(X>2*(N-W)) X=2*(N-W);
	if(X%2==1) X--;
	Y=2*Y-H;
	if(Y<0) Y=0;
	if(Y>2*(M-H)) Y=2*(M-H);
	if(Y%2==1) Y--;
	printf("%lld %lld %lld %lld",X/2,Y/2,X/2+W,Y/2+H);
	return 0;
}