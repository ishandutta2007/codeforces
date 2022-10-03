#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

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
const int MAXN = 1000010, B=10007, Z=12, M=1000000007;

ll n, m, k, u, v, x, y, t, a, b, len;
string S, ans;
ll H[MAXN];
ll tav[MAXN];
ll HH[MAXN];

void add(char ch){
	ans+=ch;
	len++;
	H[len]=(H[len-1]*B+ch+Z)%M;
}

ll get(int l, int r){ // (l, r]
	ll res=(H[r]-H[l]*tav[r-l])%M;
	if (res<0) res+=M;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*B%mod;
	cin>>n;
	while (n--){
		cin>>S;
		for (int i=1; i<=S.size(); i++) HH[i]=(HH[i-1]*B+S[i-1]+Z)%M;
		for (int i=min((ll)S.size(), len); i>=0; i--) if (get(len-i, len)==HH[i]){
			//debug(i)
			for (int j=i; j<S.size(); j++) add(S[j]);
			break ;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
/*
5
a aa aaa aaaa aab
*/