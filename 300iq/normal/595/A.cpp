#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a, b;
	int counter = 0;
	for(int i = 0; i < n; i++) {
		for(int i = 0; i < m; i++) {
			cin >> a >> b;
			counter += (a == 1 || b == 1); 
		}
	}
	cout << counter;
}