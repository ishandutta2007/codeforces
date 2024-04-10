#include <bits/stdc++.h>
using namespace std;
 
inline void write(int x) { cout << x << ' '; }
 
void transform(int n, int mul) {
	write(mul);
	switch (n) {
	case 1: 
		return;
	case 2: 
		write(2*mul); return;
	case 3: 
		write(mul), write(3*mul); return; }
	for (int q = (n-1)/2, i = 0; i < q; ++i)
		write(mul);
	transform(n/2,2*mul); }
 
int main() {
	int n;
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cin >> n, transform(n,1); }