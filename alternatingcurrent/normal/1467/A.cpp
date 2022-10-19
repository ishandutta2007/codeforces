#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int n;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		int now = 9;
		rep(i, n){
			cout << now;
			if(i == 0) now = (now + 9) % 10;
			else now = (now + 1) % 10;
		}
		cout << endl;
	}
	return 0; 
}