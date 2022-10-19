#include <iostream>
#include <vector>
using namespace std;

int dig(int i){
	int t = 0;
	while(i!=0){
		t+=(i%10);
		i/=10;
	}
	return t;
	
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for(int i=n-100; i<=n; i++){
		if(i<0) i=0;
		if(i+dig(i) == n){
			v.push_back(i);
		}
		
	}
	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << endl;
	}
	return 0;
}