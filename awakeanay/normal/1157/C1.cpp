#include <iostream>
using namespace std;

int main() {
	int n;
	std::cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
		
	int last = 0;
	int l = 0; int r = n-1;
	int ans[n];
	int out[n];
	int i;
	for(i = 0; i < n; i++) {
		if(a[l] > last && a[r] > last) {
			if(a[l] < a[r])
				out[i] = 0;
			else
				out[i] = 1;
		}
		else if(a[l] > last) {
			out[i] = 0;
		}
		else if(a[r] > last) {
			out[i] = 1;
		}
		
		//std::cout << l << " " << r << " " << last << std::endl;
		
		if((a[l] < last && a[r] < last) || l > r) {
			break;
		}
		if(out[i]) {
			last = a[r];
			r--;
		}
		else {
			last = a[l];
			l++;
		}
		//std::cout << last << std::endl;
	}
	
	std::cout << i << std::endl;
	for(int j = 0; j < i; j++) {
		if(out[j])
			std::cout << "R";
		else
			std::cout << "L";
	}
}