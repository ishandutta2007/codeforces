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
#define get(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;


int n, m, k, u, v, x, y, t, a, b, ans;
int cnt[2][2];
string S, T;

int Check(int x){
	memset(cnt, 0, sizeof(cnt));
	for (int i=0; i<n; i++) cnt[S[i]-'0'][T[i]-'0']++;
	int res=0;
	while (cnt[0][1]+cnt[1][0] && res<3*n){
		res++;
		if (!cnt[1][x]) return inf;
		cnt[0][x]++;
		cnt[1][x]--;
		swap(cnt[0][x], cnt[1][x]);
		x^=1;
		swap(cnt[0][x], cnt[1][x]);
	}
	return res;
}

int Main(){
	cin>>n>>S>>T;
	if (S==T) kill(0)
	a=b=0;
	for (int i=0; i<n; i++){
		a|=(S[i]=='1');
		b|=(T[i]=='1');
	}
	if (!a || !b) kill(-1)
	ans=min(Check(0), Check(1));
	if (ans>2*n) kill(-1)
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
9
000011111
011100011

*/