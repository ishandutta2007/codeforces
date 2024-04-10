#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

char a[10000 + 5][10000 + 5];
char v[] = {'a', 'u', 'o', 'i', 'e'};

int main(){
	ios_base::sync_with_stdio (false);
	int k, f = -1, s;
	cin >> k;
	for (int i = 1; i <= k; i++){
		if (i >= 5 and k % i == 0 and k / i >= 5){
			f = i;
			s = k / i;
			break;
		}
	}
	if (f == -1)
		return cout << -1 << endl, 0;
	for (int i = 0; i < s; i++)
		for (int j = 0; j < f; j++)
			a[i][j] = 'x';
	for (int i = 0; i < s; i++)
		for (int j = 0; j < 5; j++)
			a[i][j] = v[(i + j) % 5];
	for (int j = 5; j < f; j++)
		for (int i = 0; i < 5; i++)
			a[i][j] = v[i];
	for (int i = 0; i < s; i++)
		for (int j = 0; j < f; j++)
			cout << a[i][j];
	cout << endl;
}