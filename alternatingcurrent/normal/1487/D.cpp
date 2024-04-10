#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
ll n;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		ll lb = 1, ub = 1000001;
		while(lb <= ub){
			ll mid = (lb + ub) / 2;
			ll a = (mid + mid + 1);
			if(a * a / 2 + 1 <= n) lb = mid + 1;
			else ub = mid - 1;
		}
		cout << ub << endl; 
	}
	return 0;
}