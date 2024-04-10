#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 1e4 + 100;
bool mark[10000];
ll f[50];

int main(){
	ios_base::sync_with_stdio(false);
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= 16; i++)
		f[i] = f[i - 1] + f[i - 2];
	for (int i = 1; i <= 16; i++){
		mark[f[i]] = 1;
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		if (mark[i])
			cout << 'O';
		else
			cout << 'o';
	}
	cout << endl;
}