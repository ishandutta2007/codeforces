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

	map<int, int> cnt;

	rep(i,0,k+1){
		cout << "?";
		rep(j,0,k+1) if(j != i)
			cout << " " << j+1;
		cout << endl;
		int pos, a;
		cin >> pos >> a;
		++cnt[a];
	}
	cout << "! " << cnt.rbegin()->second << endl;
}