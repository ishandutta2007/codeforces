#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, SQ=90, NSQ=MAXN/SQ+2;

int n, m, k, u, v, x, y, t, l, r;
set<int> st1, st2, st3;

struct SQRT{
	int A[MAXN], lazy[NSQ], sz[NSQ];
	bool good[MAXN];
	pii data[NSQ][SQ];
	ll ans[NSQ];
	
	SQRT(){
		memset(lazy, 63, sizeof(lazy));
//		debug(lazy[0])
		memset(A, 63, sizeof(A));
	}
	void Build(int id){
//		debug("Build")
		int tl=id*SQ, tr=min(MAXN, tl+SQ);
		sz[id]=ans[id]=0;
		for (int i=tl; i<tr; i++) if (good[i]){
			A[i]=min(A[i], lazy[id]);
			ans[id]+=A[i];
			data[id][sz[id]++]={A[i], 1};
		}
		sort(data[id], data[id]+sz[id]);
		int len=sz[id];
		sz[id]=0;
		for (int i=len-1; i>0; i--) if (data[id][i-1].first==data[id][i].first){
			data[id][i-1].second+=data[id][i].second;
			data[id][i].second=0;
		}
		for (int i=0; i<len; i++) if (data[id][i].second) data[id][sz[id]++]=data[id][i];
	}
	void add_lazy(int id, int x){
//		debug("add_lazy")
//		debug(sz[id])
//		debugp(data[id][sz[id]-1])
		
		lazy[id]=min(lazy[id], x);
		int ted=0;
		while (sz[id] && data[id][sz[id]-1].first>=x){
			ans[id]-=1ll*data[id][sz[id]-1].first*data[id][sz[id]-1].second;
			ted+=data[id][sz[id]-1].second;
			sz[id]--;
		}
		if (ted){
			ans[id]+=1ll*ted*x;
			data[id][sz[id]++]={x, ted};
		}
	}
	void Minimize(int l, int r, int x){
		int idl=-1, idr=-1;
		while (l<r && l%SQ){
			idl=l/SQ;
			A[l]=min(A[l], x);
			l++;
		}
		while (l<r && r%SQ){
			r--;
			idr=r/SQ;
			A[r]=min(A[r], x);
		}
		while (l<r){
			add_lazy(l/SQ, x);
			l+=SQ;
		}
		if (idl!=-1) Build(idl);
		if (idr!=-1) Build(idr);
	}
	ll Get(int l, int r){
		ll res=0;
		while (l<r){
			if (l%SQ==0 && l+SQ<=r){
				res+=ans[l/SQ];
				l+=SQ;
			}
			else{
				if (good[l]) res+=min(A[l], lazy[l/SQ]);
				l++;
			}
		}
		return res;
	}
	void Set(int pos){
		good[pos]=1;
		A[pos]=min(A[pos], lazy[pos/SQ]);
		Build(pos/SQ);
	}
} S0, S1;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) st1.insert(i);
	cin>>m;
	while (m--){
		cin>>t>>l>>r;
		if (t==2) cout<<S0.Get(l, r) + S1.Get(l, r)<<'\n';
		else{
			cin>>x;
			while (1){
				auto it=st1.lower_bound(l);
				if (it==st1.end() || r<=*it) break ;
				if (x>0) st2.insert(*it);
				else st3.insert(*it);
				st1.erase(it);
			}
			if (x>0){
				while (1){
					auto it=st3.lower_bound(l);
					if (it==st3.end() || r<=*it) break ;
					S0.Set(*it);
					S1.Set(*it);
					st3.erase(it);
				}
			}
			else{
				while (1){
					auto it=st2.lower_bound(l);
					if (it==st2.end() || r<=*it) break ;
					S0.Set(*it);
					S1.Set(*it);
					st2.erase(it);
				}
			}
//			debug("set bazi done")
			if (x>0) S0.Minimize(l, r, x);
			else S1.Minimize(l, r, -x);
		}
	}
	
	
	return 0;
}
/*
3
1 4 8 10
1 4 8 -10
2 4 8

*/