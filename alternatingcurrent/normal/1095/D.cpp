//#pragma GCC optimize(2)
// Happy TLE and WA every day!
// by: zxb the vegetable chicken
#include<bits/stdc++.h>
#define mp              make_pair
#define rep(i,n)        for(int i = 0; i < n; i++)
#define foreach(i,c)    for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define BINF            0x7fffffff
#define INF             0x3f3f3f3f
#define LINF            3223372036854775807
#define END(s)          {cout<<s; return 0;}
#define CON(s)          {cout<<s; continue;}
#define BRE(s)          {cout<<s; break;}
#define pb              push_back
#define All(a)          a.begin(), a.end()  //with A in CAPITAL!!!
#define sz(a)           (int)a.size()
#define F               first
#define S               second
#define Time            clock()/CLOCKS_PER_SEC
//#define usingFiles
using namespace std;

typedef unsigned int ui;
typedef pair<int, int> pii;
typedef long long ll;

bool read(int& x)
{
	x = 0;
	int c;
	int sign = 1;
	while( (c = getchar()) < '0' || c > '9' ) if(c == '-') sign = -1;
	x = c ^ '0';
	while( (c = getchar()) >= '0' && c <= '9' ) x = (x<<3) + (x<<1) + (c ^ '0');
	x *= sign;
	return 1;
}

const int rp = 666666;
const bool debug = 1;
const bool I_good_vegetable_a = 1;

int n;
pii a[200200];

signed main(){
	ios::sync_with_stdio(false);
	#ifdef usingFiles
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n;
	rep(i, n){
		cin >> a[i].F >> a[i].S;
		a[i].F--, a[i].S--;
	}
	if(n == 3){
		cout << "1 2 3\n";
		return 0;
	}
	vector<int> ans;
	ans.pb(0);
	int x = a[0].F, y = a[0].S;
	if(a[x].F == y || a[x].S == y){
		ans.pb(x);
	} else ans.pb(y);
	while(ans.size() < n){
		if(a[ans[ans.size() - 2]].F == ans[ans.size() - 1]) ans.pb(a[ans[ans.size() - 2]].S);
		else ans.pb(a[ans[ans.size() - 2]].F);
	}
	rep(i, ans.size()){
		cout << ans[i] + 1 << " ";
	}
	return 0;
}