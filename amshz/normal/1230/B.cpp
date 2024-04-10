# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;
//int a[xn];

int main(){
	int n, k;
	cin >> n >> k;
	string a;
	cin >> a;
	if (n == k and n == 1) cout << 0;
	else if (k == 0) cout << a;
	else{
		string b = "";
		if (a[0] == '1') b += '1';
		else b += '1', k--;
		//string b = "1";
		for (int i=1; i<n; i++){
			if (a[i] != '0' and k > 0) k--, b += '0';
			else if (a[i] != 0) b += a[i];
			else b += '0';
		}
		for (int i=0; i<b.size(); i++) cout << b[i];
	}
}