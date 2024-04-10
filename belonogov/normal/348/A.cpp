#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = -1;
const int inf = 1e9;


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n;
	long long sum = 0, mx = 0, cnt;
	int x;
	cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		sum += x;
		mx = max((long long)x, mx);
	}
	cnt = n * mx - sum;
	if (cnt >= mx){
		cout << mx << endl;
		return 0;
	}
	cout << mx + (mx - cnt + n - 1 - 1) / (n - 1) << endl;
 
    return 0;
}