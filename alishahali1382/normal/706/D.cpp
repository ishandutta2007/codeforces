#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int MAXN = 200010, LOG=30;

int n, m, k, u, v, x, y, t, a, b, ans;
int TR[MAXN*LOG][3], cnt;
char ch;

void add(int x, int delta){
	int node=0;
	for (int i=LOG-1; i>=0; i--){
		int c=(x>>i)&1;
		if (!TR[node][c]) TR[node][c]=++cnt;
		node=TR[node][c];
		TR[node][2]+=delta;
	}
}

int get(int x){
	int node=0, res=0;
	for (int i=LOG-1; i>=0; i--){
		int c=(x>>i)&1;
		c^=1;
		if (TR[node][c] && TR[TR[node][c]][2]) node=TR[node][c], res|=(c<<i);
		else node=TR[node][1^c], res|=((1^c)<<i);
	}
	return res^x;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;cin>>T;
	add(0, 1);
	while (T--){
		cin>>ch>>x;
		if (ch=='+') add(x, 1);
		if (ch=='-') add(x, -1);
		if (ch=='?') cout<<get(x)<<'\n';
	}
	
	return 0;
}