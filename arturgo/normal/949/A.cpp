#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sequences;
vector<int> v0s, v1s;

int main() {
	ios_base::sync_with_stdio(false);
	string seq;
	cin >> seq;
	
	vector<int> debuts;
	
	for(int iCar = 0;iCar < (int)seq.size();iCar++) {
		char car = seq[iCar];
		if(car == '0') {
			if(v1s.empty()) {
				vector<int> nouv;
				nouv.push_back(iCar + 1);
				v0s.push_back(sequences.size());
				sequences.push_back(nouv);
			}
			else {
				int der = v1s.back();
				v1s.pop_back();
				v0s.push_back(der);
				sequences[der].push_back(iCar + 1);
			}
		}
		else {
			if(v0s.empty()) {
				cout << -1 << endl;
				return 0;
			}
			else {
				int der = v0s.back();
				v0s.pop_back();
				v1s.push_back(der);
				sequences[der].push_back(iCar + 1);
			}
		}
	}
	
	if(!v1s.empty()) {
		cout << -1 << endl;
		return 0;
	}
	
	cout << sequences.size() << endl;
	for(vector<int> sequence : sequences) {
		cout << sequence.size() << " ";
		for(int elem : sequence) {
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}