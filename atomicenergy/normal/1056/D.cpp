#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int> prev;
	prev.push_back(-1);
	for(int i=1; i<n; i++){
		int x;
		cin >> x;
		prev.push_back(x-1);
	}
	vector<int> sub;
	for(int i=0; i<n; i++){
		sub.push_back(0);
	}
	vector<int> all;
	for(int i=n-1; i>0; i--){
		if(sub[i] == 0) sub[i] = 1;
		sub[prev[i]]+=sub[i];
		all.push_back(sub[i]);
	}
	if(sub[0] == 0) sub[0] = 1;
	all.push_back(sub[0]);
	sort(all.begin(), all.end());
	for(int i=0; i<n; i++){
		cout << all[i] << " ";
	}
	
	return 0;
}