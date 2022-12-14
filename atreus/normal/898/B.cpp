#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn];

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i <= n / a; i++){
		int k = i * a;
		int l = n - k;
		if (l % b == 0){
			cout << "YES" << endl;
			cout << i << " " << l / b << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}