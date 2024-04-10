#include <bits/stdc++.h>
#pragma GCC optimize("O2")

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<"="<<x<<"\n";
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"}= {"<<x<<", "<<y<<"}\n";
#define debugp(p) cerr<<#p<<"={"<<p.first<<", "<<p.second<<"}\n";
#define debugv(v) {cerr<<#v<<": ";for (auto abcde:v) cerr<<abcde<<", ";cerr<<"\n";}
#define kill(x) return cout<<x<<"\n", 0;
#define pb push_back
#define all(x) x.begin(), x.end()

const int inf=1000000010;
const ll INF=1000000000000000010ll;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

ll ans, k, inv;
int n, m, x, y, u, v, a, b;
int A[MAXN];
vector<int> comp;

struct FENWICK{
	int fen[MAXN];
	void add(int pos, int val){
		fen[0]+=val;
		for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
	}
	int get(int pos){
		int res=0;
		for (; pos; pos-=pos&-pos) res+=fen[pos];
		return res;
	}
} fen1, fen2;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		comp.pb(A[i]);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=1; i<=n; i++){
		A[i]=lower_bound(all(comp), A[i])-comp.begin()+1;
		inv+=fen1.fen[0]-fen1.get(A[i]);
		fen1.add(A[i], +1);
		//debug(inv)
	}
	//debug(inv)
	if (inv<=k) kill(n*(n-1ll)/2);
	int r=n;
	for (int l=n; l>1; l--){
		fen1.add(A[l], -1);
		inv-=fen1.fen[0]-fen1.get(A[l]);
		inv-=fen2.get(A[l]-1);
		//debug(inv)
		while (l<r){
			inv+=fen2.get(A[r]-1);
			inv+=fen1.fen[0]-fen1.get(A[r]);
			if (inv>k){
				inv-=fen2.get(A[r]-1);
				inv-=fen1.fen[0]-fen1.get(A[r]);
				break ;
			}
			fen2.add(A[r--], +1);
		}
		ans+=n-r;
		//debug(inv)
		//debug2(l, r)
	}
	cout<<ans<<"\n";
	
	return 0;
}