#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 200 + 50, inf = -100000000;
vector <int> rest;
vector <int> v;
int a[maxn];
int n, k;

int f (int l, int r){
	rest.clear();
	v.clear();
	for (int i = 1; i < l; i++)
		rest.push_back(a[i]);
	for (int i = l; i <= r; i++)
		v.push_back(a[i]);
	if (r != n)
		for (int i = r + 1; i <= n; i++)
			rest.push_back(a[i]);
	sort (v.begin(), v.end());
	sort (rest.begin(), rest.end(), greater <int> ());
	int mx = 0, tot = 0;
	int p = k;
	for (int i = 0; i < v.size(); i++){
		if (mx >= rest.size())
			break;
		if (v[i] < rest[mx] && k > 0){
			v[i] = rest[mx];
			mx ++;
			k --;
		}
		else 
			break;
	}
	k = p;
	for (int i = 0; i < v.size(); i++){
		tot += v[i];
	}
	return tot;
}

int main (){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = inf;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			ans = max(ans, f(i, j));
	cout << ans << endl;
}