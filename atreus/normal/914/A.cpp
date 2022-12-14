#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e6 + 100;
int a[maxn];
bool mark[maxn];


int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n, greater <int> ());
	for (int i = 0; i < n; i++){
		int k = sqrt(a[i]);
		if (k * k != a[i])
			return cout << a[i] << endl, 0;
	}
}