# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

# define F first
# define S second
# define endl '\n'

const int xn = 5e3+9;
const int md = 1e9+7;

pii xy[xn];
map <int, int> ways;
bool flag, fl1;
int mark[xn], n, fl, bs;

void DFS(int v, int fl){
	mark[v] = fl;
	int td = 0;
	for (int i=0; i<n; i++){
		if ((abs(xy[i].F-xy[v].F)) + (abs(xy[i].S-xy[v].S)) <= bs) continue;
		if (((mark[i] == 1 and fl == 1) or (mark[i] == 2 and fl == 2))) fl1 = true;
		if (mark[i] != 0) continue;
		td++;
		if (fl == 1) DFS(i, 2);
		else DFS(i, 1);
	}
	if (td > 0) flag = true;
}

bool check(ll x){
	bs = x;
	fl1 = 0, fl = 0, flag = 0;
	for (int i=0; i<n; i++) mark[i] = 0;
	int ns = 0;
	for (int i=0; i<n; i++) 
		if (mark[i] == 0) DFS(i, 1), ns++;
	if (!flag) ns--;
	ways[x] = ns;
	return (!fl1);
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++) cin >> xy[i].F >> xy[i].S;
	
	ll l = -1, r = 1e4+10, mid;
	while (r-l > 1){
		mid = (l+r)/2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	ll ans = 1;
	for (int i=0; i<ways[r]; i++)
		ans *= 2, ans += md, ans %= md;
	cout << r << endl;
	cout << ans << endl;
	return 0;
}