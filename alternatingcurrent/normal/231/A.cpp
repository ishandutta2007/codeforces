#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		bool a, b, c;
		cin >> a >> b >> c;
		cnt += ((a + b + c) >= 2);
	}
	cout << cnt;
	return 0;
}