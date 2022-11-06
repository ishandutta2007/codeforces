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
	int n;
	cin >> n;

	if(n % 2){
		puts("YES");
		vi ans(2*n);
		rep(i,0,n){
			ans[i] = 2*i+1;
			ans[i+n] = 2*i+2;
			if(i % 2) swap(ans[i], ans[i+n]);
		}
		trav(x, ans) cout << x << ' ';
		cout << endl;
	} else {
		puts("NO");
	}
}