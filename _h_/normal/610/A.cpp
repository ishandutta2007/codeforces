#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n%2 == 1){
		puts("0");
		return 0;
	}
	n /= 2;
	cout << (n-1-(n%2 == 0))/2 << endl;
}