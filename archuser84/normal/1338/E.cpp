///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 8000;
bitset<N> A[N], cA[N];
vector<int> Z;
bitset<N> P, Q;
ll ans=0;
ll n;

ll inP[N], inQ[N];
void calcIn(){
	Loop(j,0,N) Loop(i,0,N) {
		inP[i] += A[j][i]&&P[j];
		inQ[i] += A[j][i]&&Q[j];
	}
}

// topo
bitset<N> vis;
void dfs(int v, vector<int>& vec){
	vis[v]=0;
	for(;;){
		cA[v] &= vis;
		int u = cA[v]._Find_first();
		if(u==N) break;
		dfs(u, vec);
	}
	vec.push_back(v);
}

vector<int> topo(bitset<N>& s)
{
	vis=s;
	Loop(i,0,N) cA[i] = A[i];
	vector<int> ans;
	Loop(v,0,N) if(vis[v])
		dfs(v, ans);
	reverse(ans.begin(), ans.end());
	return ans;
}
// topo end
void make_PQ(int X){
	for(int v : Z)
		(A[v][X]||X==v?P:Q)[v]=1;
}
int find_anti_king()
{
	int ans = Z[0];
	for(int v : Z){
		if(A[v].count() < A[ans].count())
			ans = v;
	}
	return ans;
}
void rem_no_in()
{
	static int sz[N];
	Loop(i,0,N) sz[i] = A[i].count();
	ll init_n = n;
	while(n){
		bool found=0;
		for(auto it = Z.begin(); it != Z.end(); ++it){
			int i = *it;
			if(sz[i]==n-1){
				ans += (614*init_n+1)*(n-1);
				A[i].reset();
				--n;
				Z.erase(it);
				found=1;
				break;
			}
		}
		if(!found) break;
	}
	//cout << clock() << '\n';
	if(!n) Kill(ans);
}
void In()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n){
		Loop(j,0,n/4){
			char d; cin >> d; d=d<='9'?d-'0':d-'A'+10;
			LoopR(z,4*j,4*j+4){A[i][z]=d&1; d>>=1;}
		}
	}
	Z.resize(n); iota(Z.begin(), Z.end(), 0);
	//Loop(i,0,n) {Loop(j,0,n) cout << A[i][j]; cout << '\n';}
}

void calc(vector<int>& P, vector<int>& Q)
{
	ans += P.size()*Q.size()*3;
	Loop(i,0,P.size()) Loop(j,0,i)
		ans += 3+(inQ[P[i]]==inQ[P[j]]);
	Loop(i,0,Q.size()) Loop(j,0,i)
		ans += 3+(inP[Q[i]]==inP[Q[j]]);
}

int main()
{
	In();
	rem_no_in();
	int X = find_anti_king();
	make_PQ(X);
	auto tP = topo(P);
	auto tQ = topo(Q);
	calcIn();
	calc(tP, tQ);
	cout << ans << '\n';
}