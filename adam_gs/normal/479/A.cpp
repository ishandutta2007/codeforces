#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int w=(a+b)*c;
	w=max(w,a*(b+c));
	w=max(w, a*b*c);
	w=max(w, a+b+c);
	cout << w;
}