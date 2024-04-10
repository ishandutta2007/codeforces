#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define lim 78
using namespace std;
long long d[105];
int e[105];
const long long LM=1e18;
auto G(int n,long long x){
	if(n==0)return make_pair(0,0);
	if(n==1)return make_pair((int)(x!=1),(int)(x==1));
	if(x>d[n-1]){
		auto at=G(n-2,x-d[n-1]);
		return make_pair(at.first+1,at.second);
	}
	auto at=G(n-1,x);
	int F=min(at.first,at.second+2);
	int S=min(at.first,at.second)+e[n];
	return make_pair(F,S);
}
long long F(int n,long long x,long long A,long long B){
	auto at=G(n,x);
	return min(A+at.first,B+at.second);
}
long long f(int n,long long x,long long y){
	if(n==0)return 0;
	if(n==1)return (x!=y);
	if(x>y)swap(x,y);
	if(y<=d[n-1]){
		long long ans=f(n-1,x,y);
		if(y>d[n-2]){
			ans=min(ans,F(n-1,x,0,0)+F(n-1,y,0,0)+2);
		}
		return ans;
	}
	if(x>d[n-1])return f(n-2,x-d[n-1],y-d[n-1]);
	return F(n-2,y-d[n-1],0,LM)+F(n-1,x,0,0)+1;
}
int main(){
	d[0]=1,d[1]=2;
	for(int i=2;i<=lim;++i)d[i]=d[i-1]+d[i-2];
	e[0]=0,e[1]=1;
	for(int i=2;i<=lim;++i)e[i]=e[i-2]+1;
	int T,n;
	cin>>T>>n;
	n=min(n,lim);
	while(T--){
		long long a,b;
		cin>>a>>b;
		cout<<f(n,a,b)<<endl;
	}
	return 0;
}