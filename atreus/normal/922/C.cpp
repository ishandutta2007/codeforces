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
const ll inf = 1e7 + 7, maxn = 3e5 + 500;
bool mark[inf + 100];

int main(){ // 0 --> red , 1 --> blue
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= min(k, inf); i++){
		if (mark[n % i] == 1)
			return cout << "No" << endl, 0;
		mark[n % i] = 1;
	}
	cout << "Yes" << endl;
}