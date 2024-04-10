#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	long long n, x;
	map<long long, long long> m;
	vector<long long> v;
	cin >> n >> x;
	for(int i=0; i<n; i++){
		long long k;
		cin >> k;
		m[k]++;
		v.push_back(k);
	}
	long long t = 0;
	for(int i=0; i<n; i++){
		t+=m[x^v[i]];
		
	}
	if(x==0){
		t-=n;
	}
	t/=2;
	cout << t << endl;
	return 0;
}