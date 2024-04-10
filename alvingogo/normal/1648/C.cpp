#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int mod=998244353;
void add(int& x,int y){
	x+=y;
	x-=mod*(x>=mod);
	x+=mod*(x<0);
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
int inv(int x){
	if(x<=0){
		return 0;
	}
	return x==1?1:mul((mod-mod/x),inv(mod%x));
}
struct BIT{
	int n;
	vector<int> bt;
	void init(int x){
		n=x;
		bt.resize(n+1);
	}
	void update(int x,int y){
		for(;x<=n;x+=(x&-x)){
			add(bt[x],y);
		}
	}
	int query(int x){
		int ans=0;
		for(;x>0;x-=(x&-x)){
			add(ans,bt[x]);
		}
		
		return ans;
	}
};
int main(){
	AquA;
	int n,m;
	cin >> n >> m;
	BIT bt;
	bt.init(200005);
	vector<int> cnt(200005,0),t(m),fra(200005),ifr(200005),nt(200005);
	fra[0]=ifr[0]=1;
	for(int i=1;i<200005;i++){
		fra[i]=mul(fra[i-1],i);
		ifr[i]=inv(fra[i]);
	}
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		cnt[a]++;
	}
	int nw=fra[n];
	for(int i=1;i<200005;i++){
		if(cnt[i]){
			nt[i]=cnt[i];
			bt.update(i,nt[i]);
			nw=mul(nw,ifr[cnt[i]]);
		}
	}
	int sum=0;
	int flag=0;
	for(int i=0;i<min(m,n);i++){
		cin >> t[i];
		nw=mul(nw,inv(n-i));
		add(sum,mul(nw,bt.query(t[i]-1)));
		cnt[t[i]]--;
		if(cnt[t[i]]<0){
			flag=1;
			break;
		}
		bt.update(t[i],mod-1);
		nt[t[i]]--;
		nw=mul(nw,cnt[t[i]]+1);
	}
	if(!flag && m>n){
		add(sum,nw);
	}
	cout << sum << "\n";
	return 0;
}