/**
 *    author:  Atreus
 *    created: 14.01.2019 10:34:50     
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 55;

ll f[maxn];
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	ll k;
	cin >> n >> k;
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];
	for (int i = 1; i <= n; i++){
		int x = n - i + 1;
		if (k <= f[x - 1])
			a[i] = i;
		else{
			k -= f[x - 1];
			a[i] = i + 1;
			a[i + 1] = i;
			i ++;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
}