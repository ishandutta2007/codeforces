#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main (){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cnt += a[i] / m;
		if (a[i] % m != 0)
			cnt ++;
	}
	cout << (cnt / 2) + (cnt % 2) << endl;
}