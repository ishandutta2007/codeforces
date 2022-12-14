#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = 2e5 + 100;;
const int inf = (int)1e9;
set <pair <int, int> > s, mys;
pair <int, int> p[maxn];
int ans[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i].F;
		p[i].S = i;
		s.insert (p[i]);
	}
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == '0'){
			ans[i] = (*s.begin()).S;
			mys.insert(*s.begin());
			s.erase(s.begin());
		}
		else {
			auto it = mys.end();
			it --;
			ans[i] = (*it).S;
			mys.erase(it);
		}
	}
	for (int i = 0; i < str.size(); i++)
		cout << ans[i] << " ";
}