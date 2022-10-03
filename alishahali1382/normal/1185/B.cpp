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

int n, m, k, u, v, x, y, a, b, ans;
string s, t;

int solve(){
	cin>>s>>t;
	s+=".";
	t+=".";
	vector<pair<char, int>> v1, v2;
	
	char ch=s[0];
	int cnt=1;
	for (int i=1; i<s.size(); i++){
		if (s[i]==ch) cnt++;
		else{
			v1.pb({ch, cnt});
			ch=s[i];
			cnt=1;
		}
	}
	
	ch=t[0];
	cnt=1;
	for (int i=1; i<t.size(); i++){
		if (t[i]==ch) cnt++;
		else{
			v2.pb({ch, cnt});
			ch=t[i];
			cnt=1;
		}
	}
	
	if (v1.size()!=v2.size()) kill("NO")
	for (int i=0; i<v1.size(); i++) if (v1[i].first!=v2[i].first || v1[i].second>v2[i].second) kill("NO")
	kill("YES")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	while (n--) solve();
	
	return 0;
}