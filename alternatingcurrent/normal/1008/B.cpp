#include<bits/stdc++.h>
using namespace std;
int n, a[100100], b[100100], Max = 0x3f3f3f3f;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		if(a[i] < b[i]) swap(a[i], b[i]);
	}
	for(int i = 0; i < n; i++){
		if(a[i] <= Max) Max = a[i];
		else if(b[i] <= Max) Max = b[i];
		else{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}