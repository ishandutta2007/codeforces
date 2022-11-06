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
	
	ll n,k;
	cin >> n >> k;
	if(n*(n-1)/2 < k){
		puts("Impossible");
		return 0;
	}
	ll m = 1;
	while(m*(m-1)/2 < k) ++m;
	ll d = m*(m-1)/2 - k;
	rep(_,1,m-d) cout << '(';
	cout << "()";
	rep(_,0,d) cout <<'(';
	rep(_,1,m) cout<<')';
	rep(_,m,n) cout << "()";
	cout << endl;
}