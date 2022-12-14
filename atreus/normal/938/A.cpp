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
const int inf = 1e9 + 7, maxn = 1e6 + 200;

int main(){ 
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	string k;
	bool vow = false;
	for (int i = 0; i < n; i++){
		if (s[i] != 'a' and s[i] != 'o' and s[i] != 'e' and s[i] != 'u' and s[i] != 'i' and s[i] != 'y'){
			k += s[i];
			vow = 0;
		}
		else {
			if (vow == 0){
				vow = 1;
				k += s[i];
			}
		}
	}
	cout << k << endl;
}