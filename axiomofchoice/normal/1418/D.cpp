#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
set<int> st; multiset<int> st2;
void output(){
	if(st.size()<=3)cout<<0<<endl;
	else cout<<*++st.rbegin()-*++st.begin()-*++++st2.rbegin()<<endl;
}
void Solve(){
	int n=read(),q=read(); st.clear(); st2.clear();
	st.insert(-INF/2); st.insert(INF/2);
	repeat(i,0,n)st.insert(read());
	for(auto i=st.begin();i!=st.end();i++){
		auto j=next(i);
		if(j!=st.end())st2.insert(*j-*i);
	}
	output();
	while(q--){
		int op=read(),x=read();
		if(op==0){
			auto i=st.lower_bound(x);
			st2.erase(st2.lower_bound(*i-*prev(i)));
			st2.erase(st2.lower_bound(*next(i)-*i));
			st2.insert(*next(i)-*prev(i));
			st.erase(i);
		}
		else{
			if(!st.count(x)){
				auto i=st.insert(x).first;
				st2.erase(st2.lower_bound(*next(i)-*prev(i)));
				st2.insert(*i-*prev(i));
				st2.insert(*next(i)-*i);
			}
		}
		output();
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}