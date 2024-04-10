#include <iostream>
#include <deque>
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
const int inf = 1e9 + 7, maxn = 2e5 + 100;
vector <int> v;
int b[maxn];

int main(){
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		b[i] = k + i + 1;
	}
	sort (b, b + n);
	for (int i = 1; i < n; i++)
		if (b[i] == b[i - 1])
			return cout << ":(" << endl, 0;
	for (int i = 0; i < n; i++){
		cout << b[i] - i - 1 << " ";
	}
}