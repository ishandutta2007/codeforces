#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
ull period(ull a, ull m, ull n) {
	a%=m;
	ull ans=n;
	for(ull i=1;i*i<=n;i++){
		if(n%i==0){
			if(modpow(a,i,m)==1) return i;
			if(modpow(a,n/i,m)==1) ans=n/i;
		}
	}
	return ans;
}
long long lcm(long long x,long long y){
	long long tx=x,ty=y;
	while(ty){
		tx%=ty;
		swap(tx,ty);
	}
	return x/tx*y;
}
long long solve(int cur, vector<vector<pair<long long,long long>>>& v, long long pr,long long eu){
	if(cur==v.size()){
		return eu/pr;
	}
	long long res=solve(cur+1,v,pr,eu);
	for(int i=0;i<v[cur].size();i++){
		res+=solve(cur+1,v,lcm(pr,v[cur][i].second),eu*v[cur][i].first);
	}
	return res;
}
int main(){
	long long m,x;
	scanf("%lld%lld",&m,&x);
	vector<vector<pair<long long,long long>>> v;
	for(long long p=2;p*p<=m;p++){
		if(m%p==0){
			long long tmp=1;
			v.push_back(vector<pair<long long,long long>>());
			while(m%p==0){
				m/=p;
				tmp*=p;
				v.back().push_back(make_pair(tmp/p*(p-1),period(x,tmp,tmp/p*(p-1))));
			}
		}
	}
	if(m>1) v.push_back(vector<pair<long long,long long>>(1,make_pair(m-1,period(x,m,m-1))));
	printf("%lld\n",solve(0,v,1,1));
	return 0;
}