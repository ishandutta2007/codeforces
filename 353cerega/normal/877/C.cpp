#include <iostream>
using namespace std;
int main(){
	int n, i;
	cin >> n;
	cout << (n/2+n) << endl;
	i=2;
	while (i<=n){
		cout << i << " ";
		i++;
		i++;
	}
	i=1;	
	while (i<=n){
		cout << i << " ";
		i++;
		i++;
	}
	i=2;
	while (i<=n){
		cout << i << " ";
		i++;
		i++;
	}
}