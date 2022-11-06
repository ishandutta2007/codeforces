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

ll val(char c){
	return 1LL << (c - 'a');
}

void fail(){
	cout << "No" << endl;
	exit(0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	ll t;
	string s;
	cin >> n >> t >> s;

	t -= val(s.back());
	s.pop_back();
	t += val(s.back());
	s.pop_back();

	// want to write t as alternating sum
	trav(c, s) t += val(c);
	// now want to write t / 2 as sum
	if(t < 0 || t % 2) fail();
	t /= 2;
	vi cnt(100);
	trav(c, s) ++cnt[c-'a'];
	rep(i,0,99){
		if(t % 2){
			if(!cnt[i]) fail();
			--cnt[i];
			--t;
		}
		t /= 2;
		cnt[i+1] += cnt[i]/2;
	}
	if(t) fail();
	cout << "Yes" << endl;
}