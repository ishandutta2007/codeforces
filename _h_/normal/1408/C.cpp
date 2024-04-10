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

double solve(){
	int n, l;
	cin >> n >> l;

	vi a(n+2);
	a[0] = 0, a[n+1] = l;
	rep(i,1,n+1) cin >> a[i];

	vector<double> left(n+2), right(n+2);
	rep(i,1,n+2){
		left[i] = left[i-1] + (a[i] - a[i-1]) / double(i);
	}
	rrep(i,0,n+1){
		right[i] = right[i+1] + (a[i+1] - a[i]) / double(n+1-i);
	}
	int lpos = 0, rpos = n+1;
	while(lpos+1 < rpos){
		if(left[lpos+1] < right[lpos+1]) ++lpos;
		else --rpos;
	}
	double t = max(left[lpos], right[rpos]);
	double dist = a[rpos] - a[lpos]
			- max(0., t - left[lpos]) * (lpos+1)
			- max(0., t - right[rpos]) * (n+2-rpos);
	return t + dist / (lpos + 1 + n+2 - rpos);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	cout.precision(10);

	int n;
	cin >> n;
	rep(_,0,n) cout << solve() << endl;
}