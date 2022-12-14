#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 5000 + 10;

int c[maxn], a[maxn], occ[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			occ[j] = 0;
		int mx = 1;
		for (int j = i; j <= n; j++){
			occ[c[j]] ++;
			if (occ[c[j]] > occ[mx] or (occ[c[j]] == occ[mx] and c[j] < mx))
				mx = c[j];
			a[mx] ++;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " \n"[i == n];
}