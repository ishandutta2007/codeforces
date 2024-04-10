#include <iostream>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	vector<int> x(300005);
	for(int i=1;i<=300000;i++){
		x[i]=i^x[i-1];
	}
	while(t--){
		int a,b;
		cin >> a >> b;
		int c=x[a-1];
		if(c==b){
			cout << a << "\n";
			continue;
		}
		int d=c^b;
		if(d==a){
			cout << a+2 << "\n";
		}
		else{
			cout << a+1 << "\n";
		}
	}
	return 0;
}