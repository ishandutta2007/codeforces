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

int gor(int i, int j){
	++i, ++j;
	cout << "or " << i << " " << j << endl;
	int res;
	cin >> res;
	return res;
}

int gand(int i, int j){
	++i, ++j;
	cout << "and " << i << " " << j << endl;
	int res;
	cin >> res;
	return res;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;

	vi as(n);

	vi ors(3), ans(3);
	rep(i,0,3){
		ors[i] = gor(i, (i+1)%3);
		ans[i] = gand(i, (i+1)%3);
	}

	rep(i,0,3)
		as[i] = ors[i] & ors[(i+2)%3] & (ans[i] | ~ans[(i+1)%3]);

	rep(i,3,n){
		int orr = gor(0, i);
		int ann = gand(0, i);
		as[i] = ann ^ (~as[0] & orr);
	}

	sort(all(as));

	cout << "finish " << as[k-1] << endl;
}