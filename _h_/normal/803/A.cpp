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
	vector<vi> mat(n, vi(n));
	rep(i,0,n) rep(j,i,n){
		if(k >= (i==j ? 1 : 2)){
			if(i==j){
				k -= 1;
				mat[i][j] = 1;
			} else {
				k -= 2;
				mat[i][j] = mat[j][i] = 1;
			}
		}
	}
	if(k){
		cout << -1 << endl;
	} else {
		trav(v, mat){
			trav(x, v) cout << x << ' ';
			cout << endl;
		}
	}
}