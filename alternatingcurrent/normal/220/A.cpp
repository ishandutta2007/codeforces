#include<bits/stdc++.h>
using namespace std;
int a[100100], b[100100];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += (b[i] != a[i]);
	}
	if(cnt <= 2) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}