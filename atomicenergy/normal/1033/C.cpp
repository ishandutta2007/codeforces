#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;
	vector<int> inv;
	vector<bool> a;
	vector<bool> b;
	cin >> n;
	for(int i=0; i<n+1; i++){
		v.push_back(0);
		inv.push_back(0);
		a.push_back(false);
		b.push_back(false);
	}
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v[i] = x;
		inv[x] = i;
	}
	for(int i=n; i>0; i--){
		
		for(int j=inv[i]-i; j>=0; j-=i){
			if(v[j] > i && !b[j]) a[inv[i]] = true;
			if(v[j] > i && !a[j]) b[inv[i]] = true;
		}
		for(int j=inv[i]+i; j<n; j+=i){
			if(v[j] > i && !b[j]) a[inv[i]] = true;
			if(v[j] > i && !a[j]) b[inv[i]] = true;
		}
	}
	for(int i=0; i<n; i++){
		cout << (a[i]?"A":"B");
	}
	cout << endl;
	return 0;
}