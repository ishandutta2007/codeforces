#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	long long n, k;
	cin >> n >> k;
	long long y = 0;
	long long tot = 0;
	for(int i=0; i<n; i++){
		ll x;
		cin >> x;
		tot += (y/k);
		y -= (y/k)*k;
		if(y > 0){
			tot++;
		
			if(x > (k-y)){
				x -= (k-y);
			}else{
				x = 0;
			}
		}
		y = x;
	}
	tot += y/k;
	y -= (y/k)*k;
	if(y > 0){
		tot++;
	}
	cout << tot << endl;
}