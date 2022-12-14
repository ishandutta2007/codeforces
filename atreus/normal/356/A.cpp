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
const ll mod = 1e9 + 7, maxn = 3e5 + 100;
int a[maxn];
set <int> s;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++)
		s.insert(i);
	for (int i = 1; i <= m; i++){
		int l, r, x;
		cin >> l >> r >> x;
		int idx = l;
		while (true){
			auto it = s.lower_bound(idx);
			if (*it > r)
				break;
			else {
				if (*it == x){
					idx = x + 1;
					continue;
				}
				a[*it] = x;
				s.erase(it);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}