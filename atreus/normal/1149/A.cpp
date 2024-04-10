#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if (x == 1)
			a ++;
		else
			b ++;
	}
	if (a == 0){
		for (int i = 1; i <= n; i++)
			cout << 2 << " ";
		cout << endl;
		return 0;
	}
	if (b == 0){
		for (int i = 1; i <= n; i++)
			cout << 1 << " ";
		cout << endl;
		return 0;
	}
	cout << 2 << " " << 1 << " ";
	a --, b --;
	for (int i = 1; i <= b; i++)
		cout << 2 << " ";
	for (int i = 1; i <= a; i++)
		cout << 1 << " ";
	return 0;
}