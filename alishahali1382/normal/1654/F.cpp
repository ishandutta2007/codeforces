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
const int N=18;

int n, m, k, u, v, x, y, t, a, b, sz;
int Rank[N+1][1<<N];
pii tmp[1<<N];
int P[1<<N];
char S[1<<N];

//void Solve(int bit, int tl){
//	if (!bit){
//		Rank[bit][tl]=S[tl];
//		return ;
//	}
//	int mid=tl+(1<<(bit-1)), tr=tl+(1<<bit);
//	Solve(bit-1, tl);
//	Solve(bit-1, mid);
//	
//	for (int i=0; i<(1<<(bit-1)); i++){
//		tmp[i]={Rank[bit-1][tl+i], Rank[bit-1][mid+i]};
//		tmp[i^(1<<(bit-1))]={Rank[bit-1][mid+i], Rank[bit-1][tl+i]};
//	}
//	iota(P, P+(1<<bit), 0);
//	sort(P, P+(1<<bit), [](int i, int j){
//		return tmp[i]<tmp[j];
//	});
//	Rank[bit][P[0]]=0;
//	for (int i=1; i<(1<<bit); i++)
//		Rank[bit][tl+P[i]]=Rank[bit][tl+P[i-1]]+(tmp[P[i-1]]<tmp[P[i]]);
//	
//}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=0; i<(1<<n); i++) cin>>S[i], Rank[0][i]=S[i];
	
	for (int bit=1; bit<=n; bit++){
		for (int tl=0; tl<(1<<n); tl+=(1<<bit)){
			int mid=tl+(1<<(bit-1));
			for (int i=0; i<(1<<(bit-1)); i++){
				tmp[tl+i]={Rank[bit-1][tl+i], Rank[bit-1][tl+(1<<(bit-1))+i]};
				tmp[tl+i+(1<<(bit-1))]={Rank[bit-1][tl+(1<<(bit-1))+i], Rank[bit-1][tl+i]};
			}
		}
		iota(P, P+(1<<n), 0);
		sort(P, P+(1<<n), [](int i, int j){
			return tmp[i]<tmp[j];
		});
		Rank[bit][P[0]]=0;
		for (int i=1; i<(1<<n); i++)
			Rank[bit][P[i]]=Rank[bit][P[i-1]]+(tmp[P[i-1]]<tmp[P[i]]);
		
	}
	
//	Solve(n, 0);
	
	
	
	
//	debug(Rank[1][0])
//	debug(Rank[1][1])
	
	int res=0;
	for (int i=1; i<(1<<n); i++) if (Rank[n][i]<Rank[n][res]) res=i;
//	debug(res)
	for (int i=0; i<(1<<n); i++){
		if ((i^res)<i) swap(S[i], S[i^res]);
	}
	for (int i=0; i<(1<<n); i++) cout<<S[i];
	cout<<"\n";
	
	return 0;
}