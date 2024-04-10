#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

pair<pair<int, int>, pair<int, int> > a[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].F.F >> a[i].F.S >> a[i].S.F;
		a[i].S.S = i + 1;
	}
	sort(a, a + n);
	vector<pair<int, int> > ans;
	for (int i = 0; i < n - 1; i++){
		if (a[i].F.F == a[i + 1].F.F and a[i].F.S == a[i + 1].F.S){
			mark[i] = mark[i + 1] = 1;
			ans.push_back({a[i].S.S, a[i + 1].S.S});
			i ++;
		}
	}
	int last = -1;
	for (int i = 0; i < n; i++){
		if (mark[i])
			continue;
		if (last == -1){
			last = i;
			continue;
		}
		if (a[i].F.F == a[last].F.F){
			mark[last] = mark[i] = 1;
			ans.push_back({a[last].S.S, a[i].S.S});
			last = -1;
		}
		else
			last = i;
	}
	last = -1;
	for (int i = 0; i < n; i++){
		if (mark[i])
			continue;
		if (last == -1){
			last = a[i].S.S;
			continue;
		}
		ans.push_back({last, a[i].S.S});
		last = -1;
	}
	for (auto it : ans)
		cout << it.first << " " << it.second << endl;
}