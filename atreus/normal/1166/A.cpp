#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int a[30];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		a[(int)(s[0] - 'a')] ++;
	}
	int answer = 0;
	for (int i = 0; i < 26; i++){
		int x = a[i] / 2;
		int y = a[i] - x;
		answer += x * (x - 1) / 2;
		answer += y * (y - 1) / 2;
	}
	cout << answer << endl;
}