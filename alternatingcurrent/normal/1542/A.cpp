#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int a;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int sum = 0;
		rep(i, n + n)
			cin >> a, sum += (a & 1);
		if(sum == n){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}