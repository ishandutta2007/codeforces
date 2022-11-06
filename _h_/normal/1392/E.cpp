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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(i,0,n){
		rep(j,0,n)
			cout << (i%2 ? 1LL<<(i+j) : 0) << " ";
		cout << endl;
	}
	int q;
	cin >> q;
	rep(_,0,q){
		ll k;
		cin >> k;
		int i = 0, j = 0;
		cout << i+1 << " " << j+1 << endl;
		rep(_,0,2*n-2){
			k /= 2;
			if((k+i)%2) ++i;
			else ++j;
			cout << i+1 << " " << j+1 << endl;
		}
	}
}