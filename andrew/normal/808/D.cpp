#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n;
	ll sum1 = 0LL, sum2 = 0LL;
	cin >> n;
	map <ll, ll> s1,s2;
	ll a[100001];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s2[a[i]]++;
		sum2 += a[i];
	}

	for(int i = 0; i < n; i++){
		ll d= sum1 - sum2;
		if(d % 2 == 0 && (s1[d/2] || s2[-d/2])){
			cout << "YES\n";
			return 0;
		}
		sum1 += a[i];
		sum2 -= a[i];
		s1[a[i]]++;
		s2[a[i]]--;
	}
	cout << "NO\n";
	return 0;
}