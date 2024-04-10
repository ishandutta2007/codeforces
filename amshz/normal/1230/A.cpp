# include <bits/stdc++.h>

using namespace std;

int s, a[4];

bool fn1(int n, int m){
	if (m == 4){
		if (n == s) return true;
		else return false;
	}
	if (fn1(n+a[m],m+1) or fn1(n,m+1)) return true;
	else return false;
	//return (fn1(n+a[m],m+1) or fn1(n,m+1));
}

int main(){
	for (int i=0; i<4; i++) cin >> a[i];
	s = a[0]+a[1]+a[2]+a[3];
	if (s%2 == 1){
		cout << "NO";
		return 0;
	}
	s /= 2;
	if (fn1(0,0)) cout << "YES";
	else cout << "NO";
	return 0;
}