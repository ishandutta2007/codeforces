#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	string a[100100];
	int n, k = 1;
	cin >> n >> a[0];
	for(int i = 1; i<n; i++){
		cin >> a[i];
		if(a[i] != a[i-1]) k++;
	}	
	cout << k;
	return 0;
}