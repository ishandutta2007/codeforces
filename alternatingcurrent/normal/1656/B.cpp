#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, k;
int a[200200];
map<int, int> mp;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		mp.clear();
		cin >> n >> k;
		rep(i, n){
			cin >> a[i];
			mp[a[i]]++;
		}
		bool ok = 0;
		rep(i, n)
			if(mp.count(a[i] + k))
				ok = 1;
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}