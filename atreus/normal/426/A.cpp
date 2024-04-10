#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
int a[100000];

int main (){
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	int sum = 0;
	for (int i = 0; i < n - 1; i++)
		sum += a[i];
	if (sum <= s)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}