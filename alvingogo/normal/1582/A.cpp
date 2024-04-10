#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		long long a,b,c;
		cin >> a >> b >> c;
		/*
		if(a==0 && b==0 && c%2==1){
			cout << 3 << "\n";
		}
		else if((a==1 && b==0 && c%2==1) || (a==0 && c==0 && b%2==1)){
			cout << 2 << "\n";
		}
		*/
		if((a+c)%2){
			cout << 1 << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
	return 0;
}