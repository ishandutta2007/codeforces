#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int brr[200005];

int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for(int i = 0; i < N; i++) {
			cin >> brr[i];
		}
		bool good = 1;
		for(int i = 0; i < N; i++) {
			good &= (arr[i] <= brr[i]);
		}
		for(int i = 0; i < N; i++) {
			if(arr[i] != brr[i]) {
				good &= (brr[i] <= brr[(i+1)%N]+1);
			}
		}
		cout << (good ? "yes" : "no") << "\n";
	}
}