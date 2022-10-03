#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int MAXN = 200010, SQ=120;

int n, m, k, u, v, x, y, t, a, b;
ll ans;
int A[MAXN];
int ps[MAXN];
int prv[MAXN], nxt[MAXN];
unordered_map<int, int> cnt;
deque<int> dq;
string S;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S;
	n=S.size();
	for (int i=1; i<=n; i++){
		A[i]=(S[i-1]=='1');
		prv[i]=prv[i-1];
		if (A[i-1]) prv[i]=i-1;
	}
	for (int i=n; i; i--){
		nxt[i]=nxt[i+1];
		if (A[i+1]) nxt[i]=i+1;
	}
	
	for (int k=1; k<=SQ; k++){
		cnt.clear();
		cnt[0]=1;
		for (int i=1; i<=n; i++){
			if (A[i]) ps[i]=k-1;
			else ps[i]=-1;
			ps[i]+=ps[i-1];
			
			ans+=cnt[ps[i]];
			cnt[ps[i]]++;
		}
	}
	
	for (int kk=1; kk*SQ<=n; kk++){
		dq.clear();
		for (int i=1; i<=n; i++){
			if (A[i]) dq.push_front(i);
			if (dq.size()>kk) dq.pop_back();
			if (dq.size()==kk){
				int l=i-(dq.back()-1), r=i-(prv[dq.back()]);
				l=(l+kk-1)/kk;
				r=r/kk;
				l=max(l, SQ+1);
				r++;
				if (r-l<=0) continue ;
				ans+=r-l;
			}
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}