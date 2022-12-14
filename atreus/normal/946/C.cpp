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
const int INF = 1e9 + 7, maxn = 1e5 + 50;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int c = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] - 'a' <= c and c <= 25){
			s[i] = c + 'a';
			c ++;
		}
	}
	if (c >= 26)
		cout << s << endl;
	else
		cout << -1 << endl;
}