#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e5 + 10;

char a[2][20];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1])
			return cout << "Impossible\n", 0;
	int len = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i] == s[j])
				len = j - i;
	int idx = -1;
	for (int i = 0; i < n; i++)
		if (s[i] == s[i + len]){
			idx = i;
			break;
		}
	int cnt = idx;
	for (int i = (len - 1) / 2; i >= 0; i--)
		a[0][i] = s[cnt ++];
	for (int i = 0; cnt < idx + len; i ++)
		a[1][i] = s[cnt ++];
	cnt = idx - 1;
	for (int i = (len - 1) / 2 + 1; i < 13; i++)
		a[0][i] = s[cnt --];
	for (int i = 12; cnt >= 0; i--)
		a[1][i] = s[cnt --];
	cnt = idx + len + 1;
	for (int i = (len - 1) / 2 + 1 - (len & 1); cnt < n and i < 13; i++)
		a[1][i] = s[cnt ++];
	for (int i = 12; cnt < n; i--)
		a[0][i] = s[cnt ++];
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 13; j++)
			cout << a[i][j];
		cout << endl;
	}
}