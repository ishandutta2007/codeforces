#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 5e5 + 10;
const ll mod = 1e9 + 7;

int pw[maxn];
ll x[maxn];
int cntbit[maxn], a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i < 60; i++)
		pw[i] = 2LL*pw[i-1]%mod;
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int j = 0; j < 60; j++)
			cntbit[j] = 0;
		for (int i = 0; i < n; i++)
			a[i] = 0;
		
		for (int i = 0; i < n; i++){
			cin >> x[i];
			for (int j = 0; j < 60; j++)
				if (x[i] & (1LL<<j))
					cntbit[j]++;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 60; j++){
				if (x[i] & (1LL<<j))
					a[i] = (a[i] + 1LL*n*pw[j])%mod;
				else
					a[i] = (a[i] + 1LL*cntbit[j]*pw[j])%mod;
			}
		}
		ll answer = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 60; j++)
				if (x[i] & (1LL<<j))
					answer = (answer + 1LL*pw[j]*cntbit[j]%mod*a[i]%mod) % mod;
		cout << answer << '\n';

	}
}