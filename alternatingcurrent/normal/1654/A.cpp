#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[1010];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		sort(a, a + n);
		cout << a[n - 1] + a[n - 2] << endl;
	}
	return 0;
}