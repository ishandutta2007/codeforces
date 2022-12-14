#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int mark[200];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r;
		cin >> r;
		for (int j = 1; j <= r; j++) {
			int x;
			cin >> x;
			mark[x] ++;
		}
	}
	for (int i = 1; i <= 100; i++)
		if (mark[i] == n)
			cout << i << " ";
	cout << endl;
}