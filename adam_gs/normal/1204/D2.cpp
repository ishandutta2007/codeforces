#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
set<pair<int,int>>S;
void solve() {
	S.insert({-1, -1});
	S.insert({INF, INF});
	string s;
	cin >> s;
	rep(i, s.size()) S.insert({i, s[i]-'0'});
	queue<int>q;
	rep(i, s.size()-1) if(s[i]=='1' && s[i+1]=='0') q.push(i);
	while(!q.empty()) {
		int p=q.front(); q.pop();
		rep(i, 2) {
			auto it=S.lower_bound({p, -1});
			S.erase(it);
		}
		auto it=S.lower_bound({p, -1}); --it;
		auto a=*it;
		if(a.nd==1) {
			++it;
			auto b=*it;
			if(b.nd==0) q.push(a.st);
		}
	}
	for(auto i : S) if(0<=i.st && i.st<s.size()) s[i.st]='0';
	cout << s << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}