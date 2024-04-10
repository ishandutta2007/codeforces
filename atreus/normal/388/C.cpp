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
const int inf = 1e9 + 7, maxn = 50 + 100;
vector <int> v;

int main(){
    ios_base::sync_with_stdio(false);
	ll n, fp = 0, sp = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		int s;
		cin >> s;
		for (int j = 0; j < s / 2; j++){
			int k;
			cin >> k;
			fp += k;
		}
		if (s % 2 == 1){
			int k;
			cin >> k;
			v.PB(k);
		}
		for (int j = 0; j < s / 2; j++){
			int k;
			cin >> k;
			sp += k;
		}
	}
	sort (v.begin(), v.end(), greater <int> ());
	for (int i = 0; i < v.size(); i++){
		if (i % 2 == 1)
			sp += v[i];
		else
			fp += v[i];
	}
	cout << fp << " " << sp << endl;
}