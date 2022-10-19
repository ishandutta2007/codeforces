#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
ll a, b, c;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> a >> b >> c;
		cout << a + 1000000000ll * b << " " << b << " " << c << endl;
	}
	return 0;
}