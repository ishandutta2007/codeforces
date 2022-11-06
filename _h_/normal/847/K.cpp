#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,a,b,k,f;
	cin >> n >> a >> b >> k >> f;
	map<pair<string,string>, int> tot;
	string pr = "-";
	rep(_,0,n){
		string s,t;
		cin >> s >> t;
		int cost = s==pr ? b : a;
		pr = t;
		if(s > t) swap(s,t);
		tot[{s,t}] += cost;
	}
	vi cs;
	trav(pa, tot) cs.push_back(pa.second);
	sort(all(cs));
	reverse(all(cs));
	int i;
	int ans = 0;
	for(i = 0; i < sz(cs) && i < k && cs[i]>f; ++i){
		ans += f;
	}
	for(; i < sz(cs); ++i) ans += cs[i];
	cout << ans << endl;
}