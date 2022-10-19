#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=107;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;
	int x=0, y=0, p=0;
	for(auto i : a) if(i=='+') ++x; else --x;
	for(auto i : b) {
		if(i=='+') ++y; 
		else if(i=='-') --y;
		else ++p;
	}
	int dobrze=0, zle=0;
	rep(i, 1<<p) {
		int z=y;
		rep(j, p) if(i&(1<<j)) ++z; else --z;
		if(z==x) ++dobrze;
		else ++zle;
	}
	ld licz=dobrze, mian=dobrze+zle;
	cout << fixed << setprecision(9) << licz/mian << '\n';
}