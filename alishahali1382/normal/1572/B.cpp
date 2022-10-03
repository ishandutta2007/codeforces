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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<int> out;

void apply(int x){
	out.pb(x);
	int y=A[x-1]^A[x]^A[x+1];
	A[x-1]=A[x]=A[x+1]=y;
}
void Solve(int l, int r){
	if (r-l+1<3) return ;
	if (A[l]==0){
		if (A[l+1]==0){
			Solve(l+1, r);
			return ;
		}
		if (A[l+2]==1){
			apply(l+1);
			Solve(l+2, r);
			return ;
		}
		apply(l+2);
		if (A[l+1]) apply(l+1);
		Solve(l+2, r);
		return ;
	}
	if (A[r]==0){
		if (A[r-1]==0){
			Solve(l, r-1);
			return ;
		}
		if (A[r-2]==1){
			apply(r-1);
			Solve(l, r-2);
			return ;
		}
		apply(r-2);
		if (A[r-1]) apply(r-1);
		Solve(l, r-2);
		return ;
	}
	assert(0);
}

int Main(){
	out.clear();
	k=0;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], k+=A[i];
	if (k&1) kill("NO")
	if (A[1]==0 || A[n]==0) Solve(1, n);
	else{
		int last=0, ok=0;
		for (int i=1; i<=n; i++){
			if (!last && !A[i]){
				Solve(1, i);
				Solve(i, n);
				ok=1;
				break ;
			}
			if (!A[i]) continue ;
			if (!last){
				last=i;
				continue ;
			}
			if ((i-last)&1){
				last=0;
				continue ;
			}
			debug2(last, i)
			for (int j=last+1; j<i; j+=2) apply(j);
			assert(!A[i]);
			Solve(1, i);
			Solve(i, n);
			ok=1;
			break ;
		}
		if (!ok) kill("NO")
	}
	
	cout<<"YES\n";
	cout<<SZ(out)<<"\n";
	for (int i:out) cout<<i-1<<" ";
	cout<<"\n";
	for (int i=1; i<=n; i++) assert(!A[i]);
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
10
1 1 1 1 0 1 0 1 1 1

*/