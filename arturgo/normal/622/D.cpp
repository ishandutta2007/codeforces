#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	vector<int> v;
	int iV = 1;
	for(iV = 1;iV < n;iV += 2) {
		v.push_back(iV);
	}
	
	iV -= 2;	
	for(;iV >= 1;iV -= 2) {
		v.push_back(iV);
	}
	
	iV = 2;
	for(iV = 2;iV < n;iV += 2) {
		v.push_back(iV);
	}
	
	iV -= 2;	
	for(;iV >= 2;iV -= 2) {
		v.push_back(iV);
	}
	
	v.push_back(n);
	if(n % 2 == 0)
		v.insert(v.begin() + 2 * (n - 1) - (n / 2) + 1, n);
	else
		v.insert(v.begin() + (n / 2), n);
	
	for(int e : v) {
		printf("%d ", e);
	}
	printf("\n");
	return 0;
}