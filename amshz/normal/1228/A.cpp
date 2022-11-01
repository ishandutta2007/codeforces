# include <bits/stdc++.h>

using namespace std;

bool fn1(int a){
	map <int,int> mp;
	int b;
	while (a > 0){
		b = a%10;
		a /= 10;
		mp[b]++;
		if (mp[b] > 1) return false;
	}
	return true;
}

int main(){
	int x, y;
	cin >> x >> y;
	for (int i=x; i<=y; i++){
		if (fn1(i)){
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}