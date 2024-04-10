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

inline bool read(int& x){
	x = 0;
	int c;
	int sign = 1;
	while( (c = getchar()) < '0' || c > '9' ) if(c == '-') sign = -1;
	x = c ^ '0';
	while( (c = getchar()) >= '0' && c <= '9' ) x = (x<<3) + (x<<1) + (c ^ '0');
	x *= sign;
	return 1;
}

inline bool write(int x){
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
	return 1;
}

const int rp = 666666;
const bool debug = 1;
const bool I_good_vegetable_a = 1;

signed main(){
	ios::sync_with_stdio(false);
	#ifdef usingFiles
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	if(n % 4 == 1) cout << "0 A\n";
	if(n % 4 == 2) cout << "1 B\n";
	if(n % 4 == 3) cout << "2 A\n";
	if(n % 4 == 0) cout << "1 A\n";
	return 0;
}