#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (b);)
#define trav(x,v) for(auto &x : (v))
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int mx = 111;

int s3(int x){
	return x * (x-1) * (x-2) / 6;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	map<int, int> lk;
	rep(i,2,mx) lk[s3(i) - s3(i-1)] = i;

	int n, ctr, cst;
	cin >> n >> ctr >> cst;

	vi tr(n), st(n);
	vi ix(n);
	rep(i,0,n-3) ix[i] = n-2 - i;
	ix[n-3] = 0;
	ix[n-2] = 1;
	ix[n-1] = 0;

	rep(i,0,n){
		cout << "+ " << ix[i]+1 << endl;
		int a, b;
		cin >> a >> b;
		tr[i] = a - ctr;
		st[i] = b - cst;
		ctr += tr[i];
		cst += st[i];
	}
	
	vi ans(n);

	ans[0] = lk[tr[n-1]] - 2;
	if(st[n-3] == 0) ans[1] = 0;
	else ans[1] = lk[tr[n-2]] - 1;
	ans[2] = st[n-1] / (ans[1] + 1) - 1;
	ans[3] = (st[n-2] - (ans[0] + 1)*(ans[2]+1))/(ans[2]+1) - (n>4 ? 1 : 0);
	rep(i,4,n) ans[i] = (st[n-i] - ans[i-4]*ans[i-3] - ans[i-3]*(ans[i-1]+1))/(ans[i-1]+1) - (i==n-1 ? 0 : 1);

	cout << "!";
	trav(x, ans) cout << " " << x;
	cout << endl;
}