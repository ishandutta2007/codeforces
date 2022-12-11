#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	long long a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	
	long long deb = max(a, c);
	long long fin = min(b, d);
	long long aj = 0;
	
	if(deb <= k && k <= fin)
		aj--;
	
	cout << max((long long)0, fin - deb + 1 + aj) << endl; 
	return 0;
}