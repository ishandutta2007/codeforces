#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 1e6 + 200;
vector <int> v;

int main(){ 
	ios_base::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	int k = 1;
	while (k <= n){
		if ((n - k + 1) % b == 0){
			for (int i = k + 1; i <= k + b - 1; i++)
				v.PB(i);
			v.PB(k);
			k += b;
		}
		else {
			if (k + a - 1 > n)
				return cout << -1 << endl, 0;
			for (int i = k + 1; i <= k + a - 1; i++)
				v.PB(i);
			v.PB(k);
			k += a;
		}
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}