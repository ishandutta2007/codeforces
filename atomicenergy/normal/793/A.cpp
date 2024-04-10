#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v;
	int mn = -1;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v.push_back(x);
		if(x<mn || mn == -1) mn = x;
	}
	long long t = 0;
	bool good = true;
	for(int i=0; i<n; i++){
		if(v[i]%k!=mn%k) good = false;
		t += (v[i]-mn)/k;
	}
	if(good)
	cout << t << endl;
	else{
		cout << -1 << endl;
	}
	return 0;
}