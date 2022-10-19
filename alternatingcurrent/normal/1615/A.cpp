#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int sum = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		sum = 0;
		rep(i, n){
			int val;
			cin >> val;
			sum += val; 
		}
		if(sum % n)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}