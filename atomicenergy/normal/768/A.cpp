#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int x;
	cin >> x;
	int mi = x;
	int ma = x;
	v.push_back(x);
	for(int i=1; i<n; i++){
		cin >> x;
		if(x<mi) mi = x;
		if(x>ma) ma = x;
		v.push_back(x);
	}
	int t = 0;
	for(int i=0; i<n; i++){
		if(v[i]!=mi && v[i]!=ma){
			t++;
		}
	}
	cout << t << endl;
	return 0;
}