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

	vi sum(n);

	trav(x, sum){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		x = a+b+c+d;
	}

	int ans = 1;

	trav(x, sum) ans += x > sum[0];

	cout << ans << endl;
}