#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 3010, LOG=20;

ll n, m, k, x, y, z, t, a, b, ans;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
deque<int> dq;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>a>>b>>k>>x>>y>>z;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) A[i][j]=k, k=(x*k+y)%z;
	for (int i=1; i<=n; i++){
		dq.clear();
		for (int j=1; j<=m; j++){
			while (dq.size() && A[i][dq.front()]>=A[i][j]) dq.pop_front();
			dq.push_front(j);
			if (dq.back()<=j-b) dq.pop_back();
			B[i][j]=A[i][dq.back()];
		}
	}
	for (int j=b; j<=m; j++){
		dq.clear();
		for (int i=1; i<=n; i++){
			while (dq.size() && B[dq.front()][j]>=B[i][j]) dq.pop_front();
			dq.push_front(i);
			if (dq.back()<=i-a) dq.pop_back();
			if (i>=a) ans+=B[dq.back()][j];
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}