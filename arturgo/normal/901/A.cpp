#include <iostream>
#include <vector>
using namespace std;

vector<int> hs;

vector<int> as;
vector<int> bs;

int main() {
	int height;
	cin >> height;
	
	for(int h = 0;h <= height;h++) {
		int nh;
		cin >> nh;
		hs.push_back(nh);
	}
	
	as.push_back(0);
	bs.push_back(0);
	
	bool a = false;
	for(int h = 1;h <= height;h++) {
		int e = as.size();
		if(hs[h - 1] == 1 || hs[h] == 1) {
			for(int iFois = 0;iFois < hs[h];iFois++) {
				as.push_back(e);
				bs.push_back(e);
			}
		}
		else {
			a = true;
			as.push_back(e - 1);
			bs.push_back(e);
			for(int iFois = 1;iFois < hs[h];iFois++) {
				as.push_back(e);
				bs.push_back(e);
			}
		}
	}
	
	if(a) {
		cout << "ambiguous" << endl;
		for(int ae : as) {
			cout << ae << " ";
		}
		cout << endl;
		for(int be : bs) {
			cout << be << " ";
		}
		cout << endl;
	}
	else {
		cout << "perfect" << endl;
	}
	return 0;
}