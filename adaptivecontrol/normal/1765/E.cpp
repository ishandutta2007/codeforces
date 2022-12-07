#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

void solve(){
	
	int n, a, b;
	
	cin >> n >> a >> b;
	if(a <= b){
		cout << (n+a-1) / a << "\n";
	} else {
		cout << "1\n";
	}
	
}

int T;
int main(){
	ios::sync_with_stdio(false);
	
	cin >> T;
	while(T--)
		solve();
	
	return 0;
}