#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); 
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	multiset<ll> S;
	for (int i = 1; i <= k+1; i++)
		S.insert(0);
	ll answer = 0;
	for (int i = n; i >= 1; i--){
		ll y = *S.rbegin();
		answer += y;
		S.erase(S.find(y));
		S.insert(y+a[i]);
	}
	cout << answer << endl;
}