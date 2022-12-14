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
const int inf = 1e9 + 7, maxm = 1e3 + 100, maxn = 4e6 + 500;
vector <int> v;

int cnt(int x){
	int k = 0;
	while (x > 0){
		k += x % 10;
		x /= 10;
	}
	return k;
}

int main(){
	ios_base::sync_with_stdio(false);
	v.push_back(0);
	for (int i = 1; i <= 11000000; i++){
		if (cnt(i) == 10)
			v.PB(i);
		if (v.size() >= 100000)
			break;
	}
	int n;
	cin >> n;
	cout << v[n] << endl;
}