#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	vector<int> a;
	vector<int> b;
	cin >> n;
	for(int i=0; i<n; i++){
		char x;
		cin >> x;
		a.push_back(x-'0');
	}
	for(int i=0; i<n; i++){
		char x;
		cin >> x;
		b.push_back(x-'0');
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int t=0;
	for(int i=0; i<n; i++){
		if(b[i] > a[t]) t++;
	}
	int s=0;
	for(int i=0; i<n; i++){
		if(b[i] >= a[s]) s++;
	}
	cout << n-s << endl << t << endl;
}