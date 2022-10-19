#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long gcd(long long a, long long b){
	while(b) b^=a^=b^=a%=b;
	return a;
}

int main() {
	vector<int> v;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int k;
		cin >> k;
		v.push_back(k-1);
	}
	long long m = 1;
	for(int i=0; i<n; i++){
		int k = v[i];
		long long j;
		bool b = false;
		for(j=1; !b && j<=n+2; j++){
			if(k==i){
				b = true;
			}
			k=v[k];
		}
		j--;
		if(j==n+2){
			cout << -1;
			return 0;
		}
		//cout << j;
		if(j%2==0){
			j/=2;
		}
		m = (m*j)/gcd(m,j);
	}
	cout << m;
	return 0;
}