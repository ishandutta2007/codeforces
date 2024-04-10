#include <iostream>
#include <string>
#include <set>
using namespace std;

set <string> S;

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		S.insert(s);
	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		cnt += S.count(s);
	}

	bool sol = N > M;
	if (cnt % 2)
		sol |= N == M;
	
	puts(sol ? "YES" : "NO");
	
	return 0;
}