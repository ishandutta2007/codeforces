#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int s, n;
	cin >> n >> s;
	vector<int> v;
	vector<int> w;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		w.push_back(x);
	}
	if(v[0] && v[s-1]){
		cout << "YES" << endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		if(i > s-1){
			if(v[0] && w[s-1] && v[i] && w[i]){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}