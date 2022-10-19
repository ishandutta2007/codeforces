//#pragma GCC optimize(2)
//OI
//-O2
//-O2
// Happy TLE and WA every day!
// by: zxb
#include<bits/stdc++.h>
#define mp              make_pair
#define rep(i,n)        for(int i = 0; i < n; i++)
#define foreach(i,c)    for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define BINF            0x7fffffff
#define INF             0x3f3f3f3f
#define LINF            4557430888798830399
#define pb              push_back
#define F               first
#define S               second
#define Time            clock()/CLOCKS_PER_SEC
#define read            ZXBs_fast_input
#define write           ZXBs_fast_output
//#define usingFiles
using namespace std;

typedef unsigned int ui;
typedef pair<int, int> pii;
typedef long long ll;

inline int cmax(const int &a, const int &b){ return (a > b) ? a : b; }
inline int cmin(const int &a, const int &b){ return (a > b) ? b : a; }

const int Mod = 998244353;

int w, h;

signed main(){
	ios::sync_with_stdio(false);
	#ifdef usingFiles
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> w >> h;
	int ans = 1;
	rep(i, w + h){
		ans *= 2;
		ans %= Mod;
	}
	cout << ans << endl;
	return 0;
}