#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[100100];
bool has[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 3)
			has[i] = 0;
		rep(i, n){
			cin >> a[i];
			if(a[i] < 3)
				has[a[i]] = 1;
		}
		if(has[1]){
			sort(a, a + n);
			bool ok = 1;
			rep(i, n - 1)
				if(a[i] + 1 == a[i + 1])
					ok = 0;
			cout << (ok ? "YES" : "NO") << endl;
		} else
			cout << "YES" << endl;
	}
	return 0;
}