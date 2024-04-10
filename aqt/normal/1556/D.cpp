
// Problem : D. Take a Guess
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long arr[10005];
long long aval[10005];
long long oval[10005];

long long query(string s, int a, int b){
	cout << s << " " << a << " " << b << endl;
	long long ret;
	cin >> ret;
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	for(int i = 2; i <= N; i++){
		aval[i] = query("and", 1, i);
		oval[i] = query("or", 1, i);
	}
	long long tmpa = query("and", 2, 3);
	long long tmpb = query("or", 2, 3);
	long long sum = tmpa + tmpb + aval[2] + aval[3] + oval[2] + oval[3];
	sum -= 2 * tmpa + 2 * tmpb;
	arr[1] = sum / 2;
	for(int i = 2; i <= N; i++){
		arr[i] = aval[i] + oval[i] - arr[1];
	}
	sort(arr+1, arr+1+N);
	cout << "finish " << arr[K] << endl;
}