#include<bits/stdc++.h>
#define Q 1000000007
using namespace std;
int qp(int x,long long y){
	int r=1;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
int main(){
	int p2=2,k,odd=1,d2=(Q+1)/2,d3=(Q+1)/3,ans;
	long long x,y=1;
	scanf("%d",&k);
	while(k--){
		scanf("%I64d",&x);
		if(x%2==0) odd=0;
		x%=Q-1;
		y=1LL*y*x%(Q-1);
	}
	y=(y+Q-2)%(Q-1);
	p2=qp(2,y);
	ans=1LL*(p2+(odd?-1:1))*d3%Q;
	printf("%d/%d\n",ans,p2);
	return 0;
}