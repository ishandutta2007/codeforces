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
	
	int n;
	cin >> n;
	vector<pii> events;
	rep(_,0,n){
		int l,r;
		cin >> l >> r;
		events.emplace_back(l, 1);
		events.emplace_back(r+1, -1);
	}
	sort(all(events));
	int rek = 0, cur = 0;
	trav(pa, events){
		rek = max(rek, cur += pa.second);
	}
	puts(rek <= 2 ? "YES" : "NO");
}