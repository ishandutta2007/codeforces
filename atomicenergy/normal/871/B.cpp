#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	vector<int> u;
	for(int i=0; i<n; i++){
		cout << '?' <<" " << i << " " << 0 << endl;
		fflush(stdout);
		int x;
		cin >> x;
		v.push_back(x);
	}
	for(int i=0; i<n; i++){
		cout << '?' << " " <<0 <<" " << i << endl;
		fflush(stdout);
		int x;
		cin >> x;
		u.push_back(x);
	}
	int cnt = 0;
	vector<int> z;
	for(int i=0; i<n; i++){
		bool poss = true;
		vector<int> a;
		vector<int> b;
		for(int j=0; j<n; j++){
			a.push_back(v[j] ^ i);
			if((v[j] ^ i) >= n) poss = false;
		}
		
		if(!poss) continue;
		for(int j=0; j<n; j++){
			b.push_back(u[j] ^ a[0]);
			if((u[j] ^ a[0]) >= n) poss = false;
		}
		//for(int j=0; j<n; j++){
		//	cout << b[j] << " ";
		//}
		if(!poss) continue;
		for(int j=0; j<n; j++){
			if(a[b[j]] != j) poss = false;
		}
		if(!poss) continue;
		cnt++;
		if(cnt == 1){
		 z = a;	
		}
	}
	cout << "!" << endl;
	cout << cnt << endl;
	for(int j=0; j<n; j++){
		cout << z[j] << " ";
	}
	cout << endl;
	return 0;
}