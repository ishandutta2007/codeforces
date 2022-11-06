#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	if(n%2){ // n odd, want to play second
		cout << "Second" << endl;	
		vector<vi> prs(n);
		rep(x,0,2*n){
			int i;
			cin >> i;
			prs[i-1].push_back(x);
		}
		vi bd(2*n);
		rep(i,0,n){
			int a = prs[i][0], b = prs[i][1];
			bd[a] = b;
			bd[b] = a;
		}

		vi sig(2*n, 0);	
		function<void(int, int)> set_sig = [&](int pos, int val){
			if(sig[pos]) return;
			sig[pos] = val;
			if(val == 1){
				int sop = pos<n ? pos + n : pos - n;
				set_sig(sop, -val);
			} else {
				set_sig(bd[pos], -val);
			}
		};
		rep(i,0,2*n) if(!sig[i])
			set_sig(i, 1);
		ll res = 0;
		rep(i,0,2*n) if(sig[i] == 1) res += i+1;
		int tp = res % (2*n) ? -1 : 1;
		rep(i,0,2*n) if(sig[i] == tp) cout << i+1 << " ";
		cout << endl;
	} else { // n even, want to play first
		cout << "First" << endl;
		rep(i,0,2*n) cout << (i % n) + 1  << " ";
		cout << endl;
	}
	int res;
	cin >> res; // this had better be 0
}