#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x, y;
	cin >> x >> y;
	string ans="";
	while(y) {
		ans+=char((y%2)+'0');
		y/=2;
	}
	reverse(all(ans));
	int ile=0;
	for(auto i : ans) if(i=='1') ++ile;
	map<string,int>odw;
	queue<string>q;
	string akt="";
	while(x) {
		akt+=char((x%2)+'0');
		x/=2;
	}
	reverse(all(akt));
	odw[akt]=1;
	q.push(akt);
	while(!q.empty()) {
		akt=q.front(); q.pop();
		int p=0;
		for(auto i : akt) if(i=='1') ++p;
		if(akt==ans) {
			cout << "YES\n";
			return 0;
		}
		akt+="1";
		reverse(all(akt));
		if(!odw[akt] && p<ile) {
			odw[akt]=1;
			q.push(akt);
		}
		reverse(all(akt));
		akt.pop_back();
		while(akt.back()=='0') akt.pop_back();
		reverse(all(akt));
		if(!odw[akt]) {
			odw[akt]=1;
			q.push(akt);
		}
	}
	cout << "NO\n";
}