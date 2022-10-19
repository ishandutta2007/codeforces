#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
long long n, m;

int main(){
	cin >> T;
	rep(i, T){
		cin >> n >> m;
		long long ans = n * (n+1);
		long long les = (n-m) / (m+1);
		long long mor = les+1;
		long long num_of_mor = (n-m) % (m+1);
		long long num_of_les = (m+1) - num_of_mor;
		ans -= (les*les*num_of_les + mor*mor*num_of_mor);
		ans -= (n-m);
		ans /= 2;
		cout << ans << endl;
	}
	return 0;
}