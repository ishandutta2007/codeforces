#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	int fois = n / k;
	
	while(fois * k <= n)
		fois++;
		
	cout << fois * k << endl;
	
	return 0;
}