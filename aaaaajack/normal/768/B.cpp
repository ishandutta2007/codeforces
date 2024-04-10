#include<bits/stdc++.h>
using namespace std;
long long cnt[100];
long long solve(long long n,long long l,long long r,int cur){
	long long m=(cnt[cur]+1)/2;
	if(l==1&&r==cnt[cur]) return n;
	if(r<m) return solve(n/2,l,r,cur+1);
	if(l>m) return solve(n/2,l-m,r-m,cur+1);
	return solve(n/2,l,m-1,cur+1)+solve(n/2,1,r-m,cur+1)+(n&1);
}
long long count(long long n,int cur){
	if(n<=1)  return cnt[cur]=1;
	return cnt[cur]=count(n/2,cur+1)*2+1;
}
int main(){
	long long n,l,r;
	scanf("%lld%lld%lld",&n,&l,&r);
	count(n,0);
	printf("%lld\n",solve(n,l,r,0));
	return 0;
}