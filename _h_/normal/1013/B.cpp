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

	int n, x;
	cin >> n >> x;

	vi as(n);

	trav(a, as) cin >> a;

	sort(all(as));
	rep(i,1,n) if(as[i] == as[i-1]){
		cout << 0 << endl;
		return 0;
	}

	map<int,int> cnt;
	trav(a, as) ++cnt[a&x];

	trav(a, as){
		int num = cnt[a];
		if(a == (a&x)) --num;
		if(num > 0){
			cout << 1 << endl;
			return 0;
		}
	}
	trav(pa, cnt) if(pa.second >= 2){
		cout << 2 << endl;
		return 0;
	}

	cout << -1 << endl;
	return 0;
}