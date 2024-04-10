#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	long long T , K , X;
	for(cin >> T ; T ; --T){
		cin >> K >> X; long long L = 1 , R = 2 * K - 1;
		while(L < R){
			long long mid = (L + R) >> 1;
			long long ans = mid <= K ? mid * (mid + 1) / 2 : K * (K + 1) / 2 + (K - 1 + 2 * K - mid) * (K - 1 - (2 * K - mid) + 1) / 2;
			ans < X ? L = mid + 1 : R = mid;
		}
		cout << L << endl;
	}
	return 0;
}