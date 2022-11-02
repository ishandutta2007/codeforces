#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;
void get(int x){
	if(x>=0) cout << x;
	else cout << " ";
}
int main() {
	int n, k;
	cin >> n;
	k = -n;
	for(int i = 0; i<=n; i++){
		int z = k, t = 0;
		while(t<n){
			get(z);
			cout << " ";
			z++;
			t++;
		}
		while(z>0){
			get(z);
			cout << " ";
			z--;
		}
		cout << "0\n";
		k++;
	}      
	k = -1;
	for(int i = 0; i<n; i++){
		int z = k, t=0;
		k--;
		while(t<n){
			get(z);
			cout << " ";
			t++;
			z++;
		}
		while(z>0){
			get(z);
			cout << " ";
			z--;
		}
		cout << "0\n";
	}
	return 0;
}