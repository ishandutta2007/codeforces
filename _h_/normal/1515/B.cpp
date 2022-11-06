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

string solve(){
	int n;
	cin >> n;
	if(n % 4 == 0){
		int r = sqrt(n);
		rep(t,-1,2) if((r+t) * (r+t) == n) return "YES";
	}
	if(n % 2 == 0){
		int r = sqrt(n/2);
		rep(t,-1,2) if((r+t) * (r+t) == n/2) return "YES";
	}
	return "NO";
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		cout << solve() << endl;
	}
}