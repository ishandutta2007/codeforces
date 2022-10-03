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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, l, r;
int cnt[MAXN][26];
string S;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>m;
	n=S.size();
	S="."+S;
	for (int i=1; i<=n; i++){
		memcpy(cnt[i], cnt[i-1], sizeof(cnt[i]));
		cnt[i][S[i]-'a']++;
	}
	while (m--){
		cin>>l>>r;
		if (S[l]!=S[r] || l==r){
			cout<<"Yes\n";
			continue ;
		}
		int tmp=0;
		for (int i=0; i<26; i++) tmp+=(cnt[r][i]-cnt[l-1][i]>0);
		if (tmp>=3) cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	
	return 0;
}