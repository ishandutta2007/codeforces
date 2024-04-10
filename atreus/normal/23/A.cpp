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
const int mod = 1e9 + 7, maxn = 5e3 + 100;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	set <string> myset;
	int n = s.size() - 1;
	for (int len = n; len >= 1; len --){
		for (int i = 0; i <= s.size() - len; i++){
			string k = s.substr(i, len);
			if (myset.find(k) != myset.end())
				return cout << len << endl, 0;
			myset.insert (k);
		}
	}
	cout << 0 << endl;
}