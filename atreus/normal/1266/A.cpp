#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 50;

int a[20];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		string s;
		cin >> s;
		int sum = 0;
		int n = s.size();
		for (int i = 0; i < n; i++)
			sum += (int)(s[i] - '0');
		if (sum % 3 != 0){
			cout << "cyan\n";
			continue;
		}
		for (int i = 0; i < 10; i++)
			a[i] = 0;
		for (int i = 0; i < n; i++){
			int now = (int)(s[i] - '0');
			a[now] ++;
		}
		if (a[0] == 0 or (a[0] <= 1 and a[2] == 0 and a[4] == 0 and a[6] == 0 and a[8] == 0))
			cout << "cyan\n";
		else
			cout << "red\n";
	}
}