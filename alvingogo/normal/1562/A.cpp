#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;	
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int c=max(b/2+1,a);
		cout << b-c << "\n";
	}
	return 0;
}