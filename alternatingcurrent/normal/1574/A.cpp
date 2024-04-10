#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = n; i >= 1; i--){
			rep(j, i)
				cout << '(';
			rep(j, i)
				cout << ')';
			rep(j, n - i)
				cout << "()";
			cout << endl;
		}
	}
	return 0;
}