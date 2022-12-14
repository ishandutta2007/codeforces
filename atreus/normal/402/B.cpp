#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1e3 + 100;
vector <char> al;
int dp[maxn], a[maxn];
vector <int> vl, ix;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		int m = a[i] + k;
		if (a[i] < (i - 1) * k + 1){
			dp[i] = -1;
			continue;
		}
		for (int j = i + 1; j <= n; j++){
			if (a[j] == m)
				dp[i] ++;
			m += k;
		}
	}
	int mxx = -1, idx = 0;
	for (int i = 1; i <= n; i++){
		if (dp[i] > mxx){
			mxx = dp[i];
			idx = i;
		}
	}
	for (int i = 1; i <= n; i++){
		if (i == idx)
			continue;
		int m = abs(i - idx) * k;
		if (i < idx)
			m = a[idx] - m;
		else
			m = m + a[idx];
		if (a[i] == m)
			continue;
		if (a[i] < m){
			al.push_back('+');
		}
		else
			al.push_back('-');
		ix.push_back(i);
		vl.push_back(abs(a[i] - m));
	}
	cout << al.size() << endl;
	for (int i = 0; i < al.size(); i++){
		cout << al[i] << " " << ix[i] << " " << vl[i] << endl;
	}
}