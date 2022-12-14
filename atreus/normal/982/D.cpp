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
const int maxn = 1e5 + 100;
const int inf = (int)1e9;
pair <int, int> p[maxn];
int a[maxn], dp[maxn];
set <int> seg;
multiset <int> len;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		p[i] = MP (a[i], i);
	}
	sort (p + 1, p + n + 1, greater <pair <int, int> >());
	seg.insert (1);
	dp[1] = n;
	int k = p[1].F + 1, cnt = 1;
	len.insert (n);
	for (int i = 1; i < n; i++){
		auto it = seg.upper_bound(p[i].S);
		it --;
		if (*it == p[i].S){
			if (dp[*it] == *it){
				len.erase (len.find(1));
				seg.erase (it);
			}
			else {
				len.erase (len.find(dp[*it] - *it + 1));
				len.insert (dp[*it] - *it);
				seg.insert (*it + 1);
				dp[*it + 1] = dp[*it];
				seg.erase (it);
			}
		}
		else if (dp[*it] == p[i].S){
			len.erase (len.find(dp[*it] - *it + 1));
			len.insert (dp[*it] - *it);
			dp[*it] --;
		}
		else {
			len.erase (len.find(dp[*it] - *it + 1));
			len.insert (p[i].S - *it);
			len.insert (dp[*it] - p[i].S);
			seg.insert (p[i].S + 1);
			dp[p[i].S + 1] = dp[*it];
			dp[*it] = p[i].S - 1;
		}
		it = len.end();
		it --;
		if (*it == *len.begin() and seg.size() >= cnt){
			cnt = seg.size();
			k = p[i + 1].F + 1;
		}
	}
	cout << k << endl;
}