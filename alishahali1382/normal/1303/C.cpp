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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, g, b, u, v, x, y, t, a;
string S;
bool mark[26];
char ans[60];

int solve(){
	cin>>S;
	fill(ans, ans+60, '.');
	fill(mark, mark+26, 0);
	int pos=30;
	ans[pos]=S[0];
	mark[S[0]-'a']=1;
	for (int i=1; i<S.size(); i++){
		char ch=S[i];
		if (ans[pos-1]==ch) pos--;
		else if (ans[pos+1]==ch) pos++;
		else{
			if (mark[ch-'a']) kill("NO")
			mark[ch-'a']=1;
			if (ans[pos-1]=='.') ans[--pos]=ch;
			else if (ans[pos+1]=='.') ans[++pos]=ch;
			else kill("NO")
		}
	}
	S="";
	for (int i=0; i<60; i++) if (ans[i]!='.') S+=ans[i];
	for (int i=0; i<26; i++) if (!mark[i]) S+=('a'+i);
	cout<<"YES\n";
	cout<<S<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}
/*
1
5 1 1

*/