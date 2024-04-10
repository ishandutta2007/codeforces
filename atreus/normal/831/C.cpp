#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 2e3 + 100;
int a[maxn];
vector <int> b;
map <int, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++){
		int ba;
		cin >> ba;
		if (!b.empty())
			ba += b[b.size() - 1];
		b.push_back(ba);
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (b.begin(), b.end());
	vector <int>::iterator it = unique(b.begin(), b.end());
	b.resize(distance(b.begin(), it));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b.size(); j++)
			mp[a[i] - b[j]] ++;
	int cnt = 0;
	for (auto it : mp){
		if (it.S == n)
			cnt ++;
	}
	cout << cnt << endl;
}