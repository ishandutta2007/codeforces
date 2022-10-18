#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int flag=0;
		if(a+b==c){
			flag=1;
		}
		if(b+c==a){
			flag=1;
		}
		if(a+c==b){
			flag=1;
		}
		if(a==b && c%2==0){
			flag=1;
		}
		if(c==b && a%2==0){
			flag=1;
		}
		if(a==c && b%2==0){
			flag=1;
		}
		if(flag){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}