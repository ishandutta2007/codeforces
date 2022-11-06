// written by aitch
// on 2019 10/16 at 15:35:00
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

	vi a(n), b(n);
	trav(x, a) cin >> x, --x;
	trav(x, b) cin >> x, --x;

	vi bi(n);
	rep(i,0,n) bi[b[i]] = i;

	vi c(n);
	rep(i,0,n) c[i] = bi[a[i]];

	int mx = -1;
	int fin = 0;
	trav(x, c){
		if(x > mx){
			mx = x;
		} else {
			++fin;
		}
	}
	cout << fin << endl;
}