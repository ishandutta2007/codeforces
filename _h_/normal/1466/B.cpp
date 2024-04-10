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
	int n;
	cin >> n;

	vi cnt(2 * n);
	rep(_,0,n){
		int x;
		cin >> x;
		++cnt[x-1];
	}
	int ans = 0;
	rep(i,0,2*n){
		if(cnt[i]){
			int j = i+1, tot = cnt[i];
			while(j < 2*n && cnt[j]){
				tot += cnt[j];
				++j;
			}
			ans += tot > j-i ? j-i+1 : j-i;
			i = j;
		}
	}
	cout << ans << endl;
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