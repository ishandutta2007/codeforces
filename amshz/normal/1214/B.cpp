# include <bits/stdc++.h>

using namespace std;

int main(){
	int n,b,g;
	cin >> b >> g >> n;
	long long t = 0;
	for (int i=0; i<=b; i++){
		if (n-i  <= g and n-i >= 0) t += 1;
	}
	cout << t;
}