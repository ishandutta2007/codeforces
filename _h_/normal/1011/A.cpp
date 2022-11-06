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
	
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<bool> av(26, false);
	trav(c, s) av[c-'a'] = true;

	int cur = 0;
	int w = 0;
	int prev = -2;
	rep(i,0,26) if(cur < k && av[i] && i >= prev+2){
		cur++;
		w += i+1;
		prev = i;
	}
	if(cur < k) cout << -1 << endl;
	else cout << w << endl;
}