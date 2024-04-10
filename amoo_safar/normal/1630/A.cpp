#include<bits/stdc++.h>

#define S second

using namespace std;

const int N = 5e5 + 10;


int Main(){
	
	int n, k;
	cin >> n >> k;
	
	if(n == 4 && k == 3) return cout << "-1\n", 0;
	
	vector<int> M(n / 2);
	vector<int> mk(n, 0);
	for(int i = 0; i < n / 2; i++) M[i] = n - 1 - i;
	if(k){
	if(k < n - 1){
		cout << k << ' ' << n - 1 << '\n';
		cout << 0 << ' ' << n - 1 - k << '\n';
		mk[0] = mk[k] = mk[n - 1] = mk[n-1-k] = 1;
	} else {
		cout << "0 2\n";
		cout << n - 2 << ' ' << n - 1 << '\n';
		cout << n - 3 << ' ' << 1 << '\n';
		mk[0]=mk[1]= mk[2] = 1;
	}
}
	for(int i = 0; i < n/2; i++) if(mk[i] +mk[M[i]] == 0)cout << i << ' ' << M[i] << '\n';
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int t;
	cin >> t;
	while(t --) Main();
	return 0;
}