#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 55;

string ans[MAXN];
int sol[MAXN];

string conv(int x) {
	string res = "A";
	res += x % 26 + 'a';
	res += x / 26 + 'a';
	return res;
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	
	for (int i = 0; i < N - K + 1; i++)
		cin >> ans[i];
	
	int cnt = 0;
	for (int i = 0; i < K - 1; i++)
		sol[i] = cnt++;
	
	for (int i = K - 1; i < N; i++)
		if (ans[i - K + 1] == "YES")
			sol[i] = cnt++;
		else
			sol[i] = sol[i - K + 1];
		
	for (int i = 0; i < N; i++)
		cout << conv(sol[i]) << ' ';
	cout << endl;
	
	return 0;
}