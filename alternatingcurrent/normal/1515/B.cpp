#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int num1 = n / 2, num2 = n / 4;
		if(n % 2 == 0 && sqrt(num1) == (int)sqrt(num1)) cout << "YES" << endl;
		else if(n % 4 == 0 && sqrt(num2) == (int)sqrt(num2)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}