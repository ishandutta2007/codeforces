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
const int inf = 1e9 + 7, maxn = 4e6 + 200;

int main(){
    ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i < n; i++){
		if (n % i == 0)
			cnt ++;
	}
	cout << cnt << endl;
}