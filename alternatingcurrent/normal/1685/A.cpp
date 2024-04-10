#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

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
		sort(a, a + n);
		if(n % 2 == 1){
			cout << "NO" << endl;
		} else {
			bool ok = 1;
			rep(i, n / 2 - 1)
				ok &= (a[i + 1] != a[n / 2 + i]);
			rep(i, n / 2)
				ok &= (a[i] != a[n / 2 + i]);
			if(ok){
				cout << "YES" << endl;
				rep(i, n / 2)
					cout << a[i] << " " << a[n / 2 + i] << " ";
				cout << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}