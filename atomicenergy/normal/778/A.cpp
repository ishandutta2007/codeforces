#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

	string s;
	string t;
	int n;
	int m;
	vector<int> tToI;
	vector<int> iToT;

bool test(int k){
	int y = 0;
	for(int i=0; i<n && y<m; i++){
		//cout << i << " " << y << endl;
		if(s[i] == t[y] && iToT[i]>=k) y++;
	}
	if(y==m) return true;
	return false;
}

int main() {
	
	cin >> s;
	cin >> t;
	n = s.size();
	m = t.size();
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		x--;
		tToI.push_back(x);
		iToT.push_back(0);
	}
	for(int i=0; i<n; i++){
		iToT[tToI[i]] = i;
	}
	int lo = 0;
	int hi = n-m+1;
	
	while(hi-lo>1){
		//cout << lo << "here..." << hi << endl;
		int k = (lo+hi)/2;
		if(test(k)){
			lo = k;
		}else{
			hi = k;
		}
	}
	cout << lo << endl;
	
	
}