#include<bits/stdc++.h>
using namespace std;

int arr[100003] , N , K , T;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> K; int c = 0;
		for(int i = 1 ; i <= N ; ++i){
			int a; cin >> a; c |= a;
		}
		cout << (c == 1 ? "YES" : "NO") << endl;
	}
	return 0;
}