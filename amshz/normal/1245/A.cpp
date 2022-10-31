#include <bits/stdc++.h>
using namespace std;
typedef long long           ll;
typedef long double         ld;
#define F                   first
#define S                   second

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	int qq;
	cin >> qq;
	while (qq--){
		int a, b;
		cin >> a >> b;
		if (gcd(a, b) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
}