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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
string s;
vector<int> v1[30], v2[30];
vector<pii> out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>s;
	for (int i=0; i<n; i++){
		if (s[i]=='?') v1[0].pb(i+1);
		else v1[s[i]-'a'+1].pb(i+1);
	}
	cin>>s;
	for (int i=0; i<n; i++){
		if (s[i]=='?') v2[0].pb(i+1);
		else v2[s[i]-'a'+1].pb(i+1);
	}
	
	
	for (int i=1; i<=26; i++){
		while (v1[i].size() && v2[i].size()){
			out.pb({v1[i].back(), v2[i].back()});
			v1[i].pop_back();
			v2[i].pop_back();
			//debug(i)
		}
	}
	
	for (int i=1; i<=26; i++){
		while (v1[0].size() && v2[i].size()){
			out.pb({v1[0].back(), v2[i].back()});
			v1[0].pop_back();
			v2[i].pop_back();
		}
	}
	for (int i=1; i<=26; i++){
		while (v1[i].size() && v2[0].size()){
			out.pb({v1[i].back(), v2[0].back()});
			v1[i].pop_back();
			v2[0].pop_back();
		}
	}
	while (v1[0].size() && v2[0].size()){
		out.pb({v1[0].back(), v2[0].back()});
		v1[0].pop_back();
		v2[0].pop_back();
	}
	cout<<out.size()<<'\n';
	for (pii p:out) cout<<p.first<<' '<<p.second<<'\n';
	
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/