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
const int inf = 1e9 + 7, maxn = 4e6 + 200;

int main(){
    ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	string s;
	cin >> n >> s;
	int x = 0, y = 0, city = -1;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'R')
			x ++;
		else
			y ++;
		if (x < y){
			if (city == 2)
				cnt ++;
			city = 1;
		}
		else if (x > y){
			if (city == 1)
				cnt ++;
			city = 2;
		}
	}
	cout << cnt << endl;
}