#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int main() {
	long long  n;
	long long t;
	cin >> n >> t;
	vector<long long> a, b;
	for(long long i=0; i<n; i++){
		long long x;
		cin >> x;
		x+=t;
		a.push_back(x);
	}
	vector<int> breaks;
	bool poss = true;
	long long cur = 0;
	for(long long  i=1; i<=n; i++){
		long long x;
		cin >> x;
		b.push_back(x);
		
		if(x < i) poss = false;
		if(x < cur) poss = false;
		if(x!=cur && i!=(cur+1)) poss = false;
		if(x!=cur){
			breaks.push_back(1);
		}else{
			breaks.push_back(0);
		}
		cur = x;
	}
	for(int i=1; i<n; i++){
		if(breaks[i] && !breaks[i-1] && a[i-1]+1==a[i]) poss = false;
	}
	if(!poss){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(int i=0; i<n; i++){
		if(b[i] == n){
			cout << a[n-1] + i + 1 << " ";
		}
		else{
			cout << a[b[i]] - (b[i]-i) << " ";
		}
	}
	
}