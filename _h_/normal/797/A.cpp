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

void fail(){
	cout << -1 << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vi ans;
	int lo = 2;
	while(--k){
		if(n == 1 || lo >= n) fail();
		while(n%lo) ++lo;
		if(lo >= n) fail();
		ans.push_back(lo);
		n /= lo;
	}
	trav(x, ans) cout << x << ' ';
	cout << n << endl;
}