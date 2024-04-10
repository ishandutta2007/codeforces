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

	int n, mem;
	cin >> n >> mem;
	int k = 8*mem/n;
	if(k >= 30){
		cout << 0 << endl;
		return 0;
	}
	int num = 1<<k;

	map<int,int> ren;
	rep(_,0,n){
		int a;
		cin >> a;
		++ren[a];
	}
	vi cs;
	trav(pa, ren) cs.push_back(pa.second);
	if(sz(cs) <= num){
		cout << 0 << endl;
		return 0;
	}
	int cur = 0, mx = 0;
	rep(i,0,num) cur += cs[i];
	mx = cur;
	rep(i,0,sz(cs)-num){
		cur -= cs[i];
		cur += cs[i+num];
		mx = max(mx, cur);
	}
	cout << n - mx << endl;
}