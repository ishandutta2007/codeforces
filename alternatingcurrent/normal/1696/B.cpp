#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;

int T;
int n;
int a[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		int l = 0, r = n - 1;
		while(l < n && a[l] == 0)
			l++;
		while(r >= 0 && a[r] == 0)
			r--;
		if(l >= n)
			cout << "0" << endl;
		else {
			bool ok = 1;
			for(int i = l; i <= r; i++)
				if(a[i] == 0)
					ok = 0;
			cout << (ok ? "1" : "2") << endl;
		}
	}
	return 0;
}