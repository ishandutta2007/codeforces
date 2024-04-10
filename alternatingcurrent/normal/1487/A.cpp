#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[111];
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n) cin >> a[i];
		sort(a, a + n);
		int pos = 0;
		while(pos < n && a[pos] == a[0]) pos++;
		cout << n - pos << endl;
	}
	return 0;
}