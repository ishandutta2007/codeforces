#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, m;
int cnt[200200], ans = 0;
int q;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		int add = min(a, b);
		cnt[add]++;
		if(cnt[add] == 1)
			ans++;
	}
	cin >> q;
	rep(i, q){
		int tp;
		cin >> tp;
		if(tp == 1){
			int a, b;
			cin >> a >> b;
			a--, b--;
			int add = min(a, b);
			cnt[add]++;
			if(cnt[add] == 1)
				ans++;
		}
		if(tp == 2){
			int a, b;
			cin >> a >> b;
			a--, b--;
			int add = min(a, b);
			cnt[add]--;
			if(cnt[add] == 0)
				ans--;
		}
		if(tp == 3){
			cout << n - ans << endl;
		}
	}
	return 0;
}