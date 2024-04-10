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

string s[4];

bool e(string a, string b){
	return (b[0] == (a[0] + 1)) && (b[1] == a[1]);
}
bool e2(string a, string b){
	return (b[0] == (a[0] + 2)) && (b[1] == a[1]);
}

signed main(){
	ios::sync_with_stdio(false);
	#ifdef usingFiles
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> s[0] >> s[1] >> s[2];
	sort(s, s+3);
	if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2]){
		if(s[0] == s[1] && s[1] == s[2]){
			cout << "0" << endl;
		} else {
			cout << "1" << endl;
		}
		return 0;
	}
	if(e(s[0], s[1]) || e(s[0], s[2]) || e(s[1], s[2]) || e2(s[0], s[1]) || e2(s[0], s[2]) || e2(s[1], s[2])){
		if(e(s[0], s[1]) && e(s[1], s[2])){
			cout << "0" << endl;
		} else {
			cout << "1" << endl;
		}
		return 0;
	}
	cout << "2" << endl;
	return 0;
}