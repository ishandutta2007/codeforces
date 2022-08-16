#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n;

int q(int a, int b, int c) {
	deb4('?', a, b, c)
	int x; cin >> x;
	if (x == -1) exit(0);
	return x;
}

void solve() {
	cin >> n;
	int s = q(1, 2, 3), ind = -1, x;
	vector <int> ans(n + 1, -1);
	for (int i = 4; i <= n - 2; i += 3) {
		x = q(i, i + 1, i + 2);
		if (s != x) {
			for (int j = i - 2; j < i; j++) {
				if (q(j, j + 1, j + 2) != s) {
					ind = j;
					break;
				}
			}
			if (ind == -1) ind = i;
			ans[ind + 2] = x;
			ans[ind - 1] = s;
			ans[ind] = q(ind, ind - 1, ind + 2);
			ans[ind + 1] = q(ind + 1, ind - 1, ind + 2);
			break;
		}
	}
	int z = (ans[ind] == 0)? ind : ind + 1;
	int o = (z == ind)? ind + 1 : ind;
	for (int i = 1; i < ind - 3; i += 3) {
		if (s == 0) {
			int x = q(i, i + 1, o);
			if (x == 0) {
				ans[i] = 0;
				ans[i + 1] = 0;
				ans[i + 2] = q(i + 2, z, o);
			} else {
				ans[i + 2] = 0;
				ans[i] = q(i, z, o);
				ans[i + 1] = 1 - ans[i];
			}
		} else {
			int x = q(i, i + 1, z);
			if (x == 1) {
				ans[i] = 1;
				ans[i + 1] = 1;
				ans[i + 2] = q(i + 2, z, o);
			} else {
				ans[i + 2] = 1;
				ans[i] = q(i, z, o);
				ans[i + 1] = 1 - ans[i];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] != -1) continue;
		ans[i] = q(ind, ind + 1, i);
	}
	int ct = 0;
	for (int i = 1; i <= n; i++) ct += ans[i] == 0;
	cout << "! " << ct << " ";
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) cout << i << " ";
	}
	cout << endl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}