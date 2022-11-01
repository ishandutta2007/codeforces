/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, x;
	vector<int>vec;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	int ret = 0;
	for(int i=0;i<k;i++){
		ret += vec[i];
	}
	cout << ret << endl;
	return 0;
}