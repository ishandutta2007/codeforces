#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int t;
int n, k;

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		static int c[2];
		c[0] = c[1] = 0;
		while(n--){
			int a;
			cin >> a;
			if(a % 2 == 0)
				++c[0];
			else
				++c[1];
		}
		
		if((c[1]+1) / 2 % 2 == 0){
			cout << "Alice\n";
		} else {
			if(c[1] % 2 && c[0] % 2)
				cout << "Alice\n";
			else
				cout << "Bob\n";
		}
	}
	
	return 0;
}