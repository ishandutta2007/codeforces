#include<bits/stdc++.h>
#define N 1001000
using namespace std;
long long d[N];
long long mn[100];
int main(){
	for(long long i=0;i<N;i++){
		d[i]=(i+1)*(i+1)*(i+1)-i*i*i;
	}
	long long m;
	scanf("%I64d",&m);
	long long ans=0,mx=0,tm=0;
	int cnt=0;
	while(1){
		mn[cnt]=ans;
		long long tmp=upper_bound(d+1,d+N,ans)-d;
		if(ans+tmp*tmp*tmp<=m){
			cnt++;
			ans+=tmp*tmp*tmp;
		}
		else break;
	}
	for(int j=cnt;j>0;j--){
		for(long long i=0;i<N;i++){
			if(i*i*i<=m) tm=i;
			else break;
		}
		if(m-tm*tm*tm>=mn[j-1]) m-=tm*tm*tm,mx+=tm*tm*tm;
		else{
			m=tm*tm*tm-(tm-1)*(tm-1)*(tm-1)-1;
			mx+=(tm-1)*(tm-1)*(tm-1);
		}
	}
	printf("%d %I64d\n",cnt,mx);
	return 0;
}