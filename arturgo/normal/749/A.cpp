#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int nb;
	cin >> nb;
	
	vector<int> sol;
	
	while(nb != 0) {
		if(nb == 3)
			sol.push_back(3);
		else
			sol.push_back(2);
		nb -= sol.back();
	}
	
	cout << sol.size() << endl;
	for(int s : sol)
		cout << s << " ";
	return 0;
}