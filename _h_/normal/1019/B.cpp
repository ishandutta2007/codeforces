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

int n;

int get(int i){
	cout << "? " << i << endl;
	int ans;
	cin >> ans;
	return ans;
}

int pa(int i){
	int l = get(i), r = get(i+n);
	if(l == r){
		cout << "! " << i << endl;
		exit(0);
	}
	if(l > r) return -1;
	return 1;
}

int main(){
	cin >> n;
	n /= 2;

	if(n%2 == 1){
		cout << "! -1" << endl;
		return 0;
	}

	int prev = pa(1);
	int lo = 1, hi = 1+n;
	while(lo+1 < hi){
		int mi = (lo+hi)/2;
		int nx = pa(mi);
		if(nx == prev) lo = mi;
		else hi = mi;
	}
	assert(false);
}