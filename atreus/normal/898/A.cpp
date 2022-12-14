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
	int n;
	cin >> n;
	int k = n % 10;
	int l = 10 - k;
	if (l < k)
		cout << n + l << endl;
	else
		cout << n - k << endl;
}