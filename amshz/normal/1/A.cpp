#include <iostream>
using namespace std;
 //Compiler version g++ 6.3.0

 int main()
 {
 	long long int n, m, a;
 	cin >> n >> m >> a;
 	long long int s,d;
 	s = n/a;
 	if (n % a != 0){
 		s += 1;
 	}
 	d = m/a;
 	if (m % a != 0){
 		d += 1;
 	}
 	cout << s*d;
 	return 0;
 }