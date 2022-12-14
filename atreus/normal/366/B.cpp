#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn], sum[maxn];

int main (){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		sum[i % k] += a[i];
	int ans = 1000000000, inx = 1;
	for (int i = 1; i < k; i++)
		if (sum[i] < ans){
			ans = sum[i];
			inx = i;
		}
	if (sum[0] < ans)
		inx = k;
	cout << inx << endl;
}