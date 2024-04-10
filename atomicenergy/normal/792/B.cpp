#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;


int main() {
	
	cin >> n >> k;
	vector<int> v;
	
	int ind = 0;
	for(int i=0; i<n; i++){
		v.push_back(i+1);
	}
	for(int i=0; i<k; i++){
		int x;
		cin >> x;
		ind +=x;
		ind %=v.size();
		cout << v[ind] << " ";
		v.erase(v.begin()+ind);
	}
	cout << endl;
	
	return 0;
}