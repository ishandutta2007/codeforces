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
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vi p(n);
	trav(x, p) cin >> x, --x;

	int par = 0;
	vector<bool> vis(n, false);

	rep(i,0,n) if(!vis[i]){
		par = 1 - par;
		int j = i;
		do {
			vis[j] = true;
			j = p[j];
		} while(j != i);
	}

	if(!par) cout << "Petr" << endl;
	else    cout << "Um_nik" << endl;
}