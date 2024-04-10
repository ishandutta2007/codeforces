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

const int mx = 1e5, vmx = 7001;
typedef bitset<vmx> bs;

bs ms[mx];

bs divs[vmx], mob[mx];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	rep(i,1,vmx) for(int j = i; j < vmx; j += i)
		divs[j].set(i);

	vi sqf(vmx, 1);
	rep(i,2,vmx){
		int s = i*i;
		for(int j = s; j < vmx; j += s) sqf[j] = 0;
	}
	rep(j,1,vmx) for(int i = 1; i*j < vmx; ++i)
		mob[j][i*j] = sqf[i];

	rep(_,0,q){
		int t;
		cin >> t;
		if(t == 1){
			int x, v;
			cin >> x >> v;
			--x;
			ms[x] = divs[v];
		} else if(t == 2){
			int x, y, z;
			cin >> x >> y >> z;
			--x, --y, --z;
			ms[x] = ms[y] ^ ms[z];	
		} else if(t == 3){
			int x, y, z;
			cin >> x >> y >> z;
			--x, --y, --z;
			ms[x] = ms[y] & ms[z];
		} else if(t == 4){
			int x, v;
			cin >> x >> v;
			--x;
			cout << (ms[x] & mob[v]).count()%2;
		}
	}
	cout << endl;
}