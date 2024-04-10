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
const int inf = 1e9 + 7, maxn = 1e6 + 500;
bool lef[maxn],  rig[maxn];

int main(){ // 0 --> red , 1 --> blue
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	string k;
	char c = 'a';
	for (int i = s.size() - 1; i >= 0; i--){
		if (s[i] >= c){
			k += s[i];
			c = s[i];
		}
	}
	for (int i = k.size() - 1; i >= 0; i--)
		cout << k[i];
	cout << endl;
}