#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops,fast-math")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef /*long */double ld;
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
const int MAXN = 81, LOG=20;

int n, m, k, u, v, x, y, a, b;
int L[MAXN], R[MAXN];
ld dp[MAXN][MAXN], ans[MAXN][MAXN];
vector<int> comp;

/*

test:
3
2 3
1 3
2 4

too 3 nafar
ehtemale inke 1 aval she !!!!!!!!!==== ehtemal inke 1 az 2 bala tar she * ehtemal inke 1 az 3 bala tar she
chon in adada miangin ehtemah bishtar shodan 1 az 2 be ezaye hame ye halate 1 ee 


FUCK This JOOOOOB :(

ld get(int l, int r, int ll, int rr){
	//cerr<<l<<' '<<r<<' '<<ll<<' '<<rr<<endl;
	if (l==ll && r==rr) return .5;
	if (l>ll) return 1-get(ll, rr, l, r);
	if (r<=ll) return 1;
	vector<int> vec={l, r, ll, rr};
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	ld res=0;
	for (int i=1; i<vec.size(); i++) for (int j=1; j<vec.size(); j++){
		if (l<=vec[i-1] && vec[i]<=r){
			if (ll<=vec[j-1] && vec[j]<=rr){
				res+=get(vec[i-1], vec[i], vec[j-1], vec[j])*(vec[i]-vec[i-1])/(r-l)*(vec[j]-vec[j-1])/(rr-ll);
			}
		}
	}
	return res;
}*/

void Fuck(int i, int l, int rrr){
	memset(dp, 0, sizeof(dp));   //  dp[shit][r][t]  shit taye aval   r ta raste segment   t ta toosh
	dp[0][0]=1;
	int shit=0;
	for (int j=1; j<=n; j++) if (i!=j){
		shit++;
		ld ll=L[j], rr=R[j];
		ld toosh=0, rast=0;
		if (ll<=l && rrr<=rr) toosh=(rrr-l)/(rr-ll);
		if (rrr<rr) rast=(rr-max((ld)rrr, ll))/(rr-ll);
		ld chap=1.-rast-toosh;
	
		for (int rt=shit; ~rt; rt--){
			for (int r=rt; ~r; r--){
				int t=rt-r;
				dp[r][t]=dp[r][t]*chap;
				if (r) dp[r][t]+=dp[r-1][t]*rast;
				if (t) dp[r][t]+=dp[r][t-1]*toosh;
				
			}
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>L[i]>>R[i], comp.pb(L[i]), comp.pb(R[i]);
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());

	for (int i=1; i<=n; i++){
		for (int j=1; j<comp.size(); j++) if (L[i]<=comp[j-1] && comp[j]<=R[i]){
			int l=comp[j-1], rrr=comp[j];
			Fuck(i, l, rrr);
			for (int r=0; r<n; r++) for (int t=0; r+t<n; t++)/* for (int pos=0; pos<=t; pos++) */if (abs(dp[r][t])>eps){
				ans[i][r]+=dp[r][t]/(t+1)*(rrr-l)/(R[i]-L[i]);
				ans[i][r+t+1]-=dp[r][t]/(t+1)*(rrr-l)/(R[i]-L[i]);
				// feel the power of partial sums!!!
			}
		}
	}
	
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ans[i][j]+=ans[i][j-1];
	
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cout<</*setprecision(8)<<fixed<<*/ans[i][n-j]<<" \n"[j==n];
	
	return 0;
}