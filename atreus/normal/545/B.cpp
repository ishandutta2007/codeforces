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
const int inf = 1e9 + 7, maxn = 3e5 + 500;
ll mark[maxn], dp[maxn], par[maxn], n;
vector <pair <pair <int, int>, int> > v[maxn];
vector <int> ans;

int main(){ // 0 --> red , 1 --> blue
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			cnt ++;
	if (cnt % 2 == 1)
		return cout << "impossible" << endl, 0;
	int k = cnt / 2;
	for (int i = 0; i < a.size(); i++){
		if (a[i] == b[i])
			cout << '1';
		else if (k > 0){
			cout << a[i];
			k --;
		}
		else
			cout << b[i];
	}
	cout << endl;
}