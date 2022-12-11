#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bitset<1000> der, cur;

int main() {
	int n;
	cin >> n;
	
	cur = 1;
	
	for(int iFois = 0;iFois < n;iFois++) {
		bitset<1000> nouv = (cur << 1) ^ der;
		der = cur;
		cur = nouv;
	}
	
	vector<int> coeffsA, coeffsB;
	for(int i = 0;i < 1000;i++) {
		coeffsA.push_back(der[i]);
		coeffsB.push_back(cur[i]);
	}
	
	while(coeffsA.back() == 0)
		coeffsA.pop_back();
	while(coeffsB.back() == 0)
		coeffsB.pop_back();
	
	cout << coeffsB.size() - 1 << endl;
	for(int coeff : coeffsB)
		cout << coeff << " ";
	cout << endl;
	cout << coeffsA.size() - 1 << endl;
	for(int coeff : coeffsA) 
		cout << coeff << " ";
	cout << endl;
	
	return 0;
}