#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

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
		if(n == 3){
			if(a[1] % 2 == 1)
				cout << "-1" << endl;
			else
				cout << a[1] / 2 << endl;
		} else {
			bool ok = 0;
			ll sum = 0;
			for(int i = 1; i < n - 1; i++){
				ok |= (a[i] >= 2);
				sum += (a[i] + 1) / 2;
			}
			if(!ok)
				cout << "-1" << endl;
			else
				cout << sum << endl;
		}
	}
	return 0;
}