#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, long long> k;
	
	for(int i=1; i<=m; i++){
		k[(i*i)%m] += n/m;
		if(n%m >= i ) k[(i*i)%m]++;
	}
	long long tot = 0;
	for(int i=0; i<m; i++){
		tot += k[i] * k[(m-i)%m];
	}
	cout << tot << endl;
	return 0;
}