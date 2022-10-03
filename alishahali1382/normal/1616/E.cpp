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

ll ans;
int n, m, k, u, v, x, y, t, a, b;
int fen[MAXN];
string S, T;
vector<int> vec[26];

void add(int pos, int x){
	for (pos+=4; pos<n+10; pos+=pos&-pos) fen[pos]+=x;
}
int get(int pos){
	int res=0;
	for (pos+=4; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

int Main(){
	ans=0;
	for (int i=0; i<26; i++) vec[i].clear();
	cin>>n>>S>>T;
	if (S<T) kill(0)
	string SS=S;
	sort(all(SS));
	if (SS>=T) kill(-1)
	fill(fen, fen+n+10, 0);
	for (int i=0; i<n; i++) add(i, +1);
	for (int i=n-1; ~i; i--) vec[S[i]-'a'].pb(i);
	
	int pref=0;
	while (SS[pref]==T[pref]) pref++;
	/*
	vector<int> shit;
	for (int i=0; i<pref; i++){
		shit.pb(vec[T[i]-'a'].back());
		vec[T[i]-'a'].pop_back();
	}
	sort(all(shit));
	for (int i=0; i<pref; i++) ans+=shit[i]-i; // wtf indeed
	
	int ptr=0;
	for (int i=0; i<n; i++){
		if (ptr<pref && shit[ptr]==i) ptr++;
		else{
			if (S[i]>=T[pref]) ans++;
			else break ;
		}
	}*/
	ll sum=0;
	ans=INF;
	for (int i=0; i<n; i++){
		for (int c=0; c+'a'<T[i]; c++)
			if (SZ(vec[c])) ans=min(ans, sum+get(vec[c].back())-1);
		
		int c=T[i]-'a';
		if (!SZ(vec[c])) break ;
		add(vec[c].back(), -1);
		sum+=get(vec[c].back());
		vec[c].pop_back();	
	}
	
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}