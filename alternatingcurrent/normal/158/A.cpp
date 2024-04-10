#include<bits/stdc++.h>
using namespace std;
int a[55];
int main(){
	int n, k;
	cin >> n >> k;
	k--;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int target = a[k];
	int Count = 0;
	for(int i = 0; i < n; i++){
		Count += (a[i] >= target && a[i] > 0);
	}
	cout << Count << endl;
	return 0;
}