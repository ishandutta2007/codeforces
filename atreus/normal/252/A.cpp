#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
const int maxl = 30 + 1;

int a[maxn];
int rc[maxn * maxl], lc[maxn * maxl];

int newint = 2;
void add(int x){
	int cur = 1;
	for (int i = 29; i >= 0; i--){
		if (x & (1 << i)){
			if (rc[cur] == 0)
				rc[cur] = newint ++;
			cur = rc[cur];
		}
		else{
			if (lc[cur] == 0)
				lc[cur] = newint ++;
			cur = lc[cur];
		}
	}
}

int get(int x){
	int cur = 1, ret = 0;
	for (int i = 29; i >= 0; i--){
		if (x & (1 << i)){
			if (lc[cur] != 0){
				cur = lc[cur];
				ret += (1 << i);
			}
			else{
				cur = rc[cur];
			}
		}
		else{
			if (rc[cur] != 0){
				cur = rc[cur];
				ret += (1 << i);
			}
			else{
				cur = lc[cur];
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0, pre = 0;
	add(0);
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		pre ^= a;
		ans = max(ans, get(pre));
		add(pre);
	}
	cout << ans << endl;
}