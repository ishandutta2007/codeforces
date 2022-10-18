#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n,h;
		cin >> n >> h;
		int a=0,b=0;
		int c;
		for(int i=0;i<n;i++){
			cin >> c;
			if(c>a){
				b=a;
				a=c;
			}
			else if(c>b){
				b=c;
			}
		}
		int j=2*(h/(a+b));
		h%=(a+b);
		//cout << a << b << endl;
		if(h>0){
			h-=a;
			j++;
		}
		if(h>0){
			h-=b;
			j++;
		}
		cout << j << "\n";
	}
	return 0;
}