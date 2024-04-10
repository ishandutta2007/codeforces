#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int h, w;
	cin >> h >> w;

	vector<string> ans(h, string(w, '0'));

	int i = 0, j = 0;

	auto isback = [&](){
		return i <= 1 && j == 0;
	};

	auto iscorner = [&](){
		return (i == 0 || i == h-1) && (j == 0 || j == w-1);
	};

	bool done = false;

	auto nxt = [&](){
		if(i == 0 && j < w-1) ++j;
		else if(j == w-1 && i < h-1) ++i;
		else if(i == h-1 && j > 0) --j;
		else --i;

		done = done || isback();
	};

	while(true){
		ans[i][j] = '1';
		nxt();
		if(iscorner()) nxt();
		nxt();
		if(done) break;
	}

	trav(s, ans) cout << s << endl;
	cout << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}