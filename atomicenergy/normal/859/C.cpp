#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	vector<int> bo;
	vector<int> al;
	int t = 0;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		a.push_back(x);
		t+=a[i];
	}
	bo.push_back(0);
	al.push_back(0);
	for(int i=n-1; i>=0; i--){
		int bb = max(bo[bo.size()-1], al[al.size()-1] + a[i]);
		int aa = min(al[al.size()-1] + a[i], bo[bo.size()-1]);
		bo.push_back(bb);
		al.push_back(aa);
	}
	cout << t - bo[bo.size()-1] << " " << bo[bo.size()-1] << endl;
}