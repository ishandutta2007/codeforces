#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[5000];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int m = 100000;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += m;
	}
	cout << n + 1 << endl;
	cout << 1 << " " << n << " " << m << endl;
	for (int i = 1; i <= n; i++){
		cout << 2 << " " << i << " " << a[i] - i << endl;
	}
}