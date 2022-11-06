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

const int mx = 1e6+1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,a;
	cin >> n >> a;
	vi cs(n);
	trav(c,cs) cin >> c;
	vector<int> cnt(mx,0);
	vector<bool> kvar(mx, 1);
	kvar[a] = 0;
	vector<vi> ls(n+1);
	rep(i,1,mx+1) if(i != a)
		ls[0].push_back(i);
	trav(c, cs){
		if(c == a){
			trav(x, ls[cnt[a]]){
				if(cnt[x] > cnt[a]){
					ls[cnt[x]].push_back(x);
				} else {
					kvar[x] = 0;
				}
			}
		}
		++cnt[c];
	}
	rep(i,1,mx) if(kvar[i]){
		cout << i << endl;
		return 0;
	}
	cout << -1 << endl;
}