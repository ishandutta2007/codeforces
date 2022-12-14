#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
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
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 1e4 + 100;
map <string, string> mp;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;
		mp[b + ';'] = a;
	}
	for (int i = 0; i < m; i++){
		string a, b;
		cin >> a >> b;
		cout << a << " " << b << " #" << mp[b] << endl;
	}
}