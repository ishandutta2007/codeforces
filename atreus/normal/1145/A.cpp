#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int a[26];

int answer = 1;

void find(int L, int R){
	if (L + 1 == R)
		return;
	bool sorted = 1;
	for (int i = L; i < R - 1; i++)
		if (a[i] > a[i + 1])
			sorted = 0;
	if (sorted){
		answer = max(answer, R - L);
		return;
	}
	int mid = (L + R) >> 1;
	find(L, mid);
	find(mid, R);
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	find(0, n);
	cout << answer << endl;
}