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
const int inf = 1e9 + 7, maxn = 2000 + 100;

string rev (string k){
	string a;
	for (int i = k.size() - 1; i >= 0; i--)
		a += k[i];
	return a;
}

int main(){ 
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	cout << s << rev(s) << endl;
}