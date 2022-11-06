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

	vi cs(n);
	trav(x, cs) cin >> x, x = n-x;

	vi cnt(n+1);
	trav(x, cs) ++cnt[x];

	rep(i,1,n+1) if(cnt[i]%i){
		puts("Impossible");
		return 0;
	}
	vi cur(n+1), ix(n+1);
	int idx = 1;
	cout << "Possible" << endl;
	rep(i,0,n){
		if(cur[cs[i]]==0){
			cur[cs[i]] = cs[i];
			ix[cs[i]] = idx++;
		}
		--cur[cs[i]];
		cout << ix[cs[i]] << ' ';
	}
	cout << endl;
}