// Black lives matter !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
	
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 998244353;
const int N = 5e5 + 10;
const int Inf = 2000000100;
const ll Log = 30;

int c0, c1;
int n, mk[N], mt[N], on[N];

int mn, mx, pl, pr;
int A[N], B[N];

void Plant(int x, int left){
	if(mk[x] || mk[mt[x]]) return ;
	
	if(on[x]) c0 ++;
	else c1 ++;

	int mc = mt[x];
	mk[x] = mk[mc] = 1;

	if(left == 1){
		A[pl] = x;
		B[pl] = mc;
		pl ++;
		while(mn > mc){
			mn --;
			Plant(mn, 0);
		}
	} else {
		A[pr] = x;
		B[pr] = mc;
		pr --;
		while(mx < mc){
			mx ++;
			Plant(mx, 1);
		}
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	mn = n + n + 1; mx = 0;
	pl = 1; pr = n;
	int a, b;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		mt[a] = b;
		mt[b] = a;
		on[a] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n + n; i++){
		Plant(i, 1);
		ans += min(c0, c1);
		c0 = c1 = 0;
	}
	// cerr << "! ";
	// for(int i = 1; i <= n; i++) cerr << A[i] << ' ';
	// cerr << "\n! ";
	// for(int i = 1; i <= n; i++) cerr << B[i] << ' ';
	// cerr << '\n';
	for(int i = 2; i <= n; i++){
		if(A[i] < A[i - 1] || B[i] > B[i - 1])
			return cout << -1 << '\n', 0;
	}
	cout << ans << '\n';
	return 0;
}
/*

*/