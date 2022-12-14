#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#include <stack>

#define F first
#define S second
#define PB push_back
using namespace std;

const int maxn = 2e3 + 100;
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int c = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[j] < a[i])
				c ^= 1;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		if (len % 4 == 2 || len % 4 == 3)
			c ^= 1;
		if (c == 1)
			cout << "odd" << endl;
		else
			cout << "even" << endl;
	}
}