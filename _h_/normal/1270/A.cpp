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
	
	int n;
	cin >> n;

	rep(_,0,n){
		int n, k1, k2, x;
		cin >> n >> k1 >> k2;
		string ans = "YES";
		rep(_,0,k1) cin >> x;
		rep(_,0,k2){
			cin >> x;
			if(n == x) ans = "NO";
		}
		cout << ans << endl;
	}
}