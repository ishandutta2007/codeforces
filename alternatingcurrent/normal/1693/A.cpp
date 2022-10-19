#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll a[200200];

int main(){
	ios::sync_with_stdio(false); 
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		while(n && a[n - 1] == 0)
			n--;
		ll nowsum = 0;
		rep(i, n){
			nowsum += a[i];
			if(i != n - 1 && nowsum <= 0){
				nowsum = -1;
				break;
			}
		}
		if(nowsum != 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}