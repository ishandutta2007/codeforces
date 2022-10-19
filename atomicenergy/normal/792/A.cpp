#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int min= 0x7fffffff;
	int t = 0;
	for(int i=0; i<n-1; i++){
		int x = v[i+1]-v[i];
		if(x<min){
			min = x;
			t=0;
		}
		if(x==min){
			t++;
		}
	}
	cout << min << " " << t << endl;
	return 0;
}