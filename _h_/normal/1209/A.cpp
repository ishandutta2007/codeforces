#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vi as(n);
	trav(a, as) cin >> a;
	sort(all(as));

	vi ls;
	trav(a, as){
		trav(l, ls) if(a % l == 0) goto ok;
		ls.push_back(a);
		ok: ;
	}
	cout << sz(ls) << endl;
}