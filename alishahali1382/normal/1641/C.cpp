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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, l, r, t, a, b, ans;
int A[MAXN];
set<int> st;

struct Segment{
	int seg[MAXN<<1];
	
	void Build(){
		memset(seg, 63, sizeof(seg));
	}
	void Set(int pos, int val){
		pos+=n;
		seg[pos]=min(seg[pos], val);
		for (; pos>1; pos>>=1) seg[pos>>1]=min(seg[pos], seg[pos^1]);
	}
	int Get(int l, int r){
		int res=seg[0];
		for (l+=n, r+=n; l<r; l>>=1, r>>=1){
			if (l&1) res=min(res, seg[l++]);
			if (r&1) res=min(res, seg[--r]);
		}
		return res;
	}	
} seg;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) st.insert(i);
	
	seg.Build();
	
	
	
	while (m--){
		cin>>t;
		if (t==0){
			cin>>l>>r>>x;
			if (!x){
				auto it=st.lower_bound(l);
				while (it!=st.end() && *it<=r) it=st.erase(it);
				continue ;
			}
			seg.Set(l, r);
			continue ;
		}
		cin>>x;
		int f0=0, f1=0;
		
		f1=(st.find(x)!=st.end());
		
		int l=0, r=n+1;
		auto it=st.lower_bound(x);
		
		if (it!=st.begin()) l=*--it;
		while (it!=st.end() && *it<=x) it++;
		if (it!=st.end()) r=*it;
		
//		debug2(l, r)
		
		int mn=seg.Get(l+1, x+1);
		
//		debug(mn)
		
		f0=(mn>=r);
		
//		debug2(f0, f1)
		
		if (!f0) cout<<"YES\n";
		else if (!f1) cout<<"NO\n";
		else cout<<"N/A\n";
		
	}
	
	
	return 0;
}
/*

6 3
0 4 5 0
0 4 6 1
1 6


*/