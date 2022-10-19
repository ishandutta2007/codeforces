#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int solve(int l, int r){
	if(l>r) return 1;
	if(l==r) return l;
	int m1 = (l+r)/2;
	int m2 = (l+r)/2+1;
	cout << "1 " << m1 << " " << m2 << endl;
	fflush(stdout);
	string s;
	cin >> s;
	if(s=="TAK"){
		return solve(l, m1);
	}
	else{
		return solve(m2, r);
	}
}

bool check(int a, int x){
	cout << "1 " << a << " " << x << endl;
	fflush(stdout);
	string s;
	cin >> s;
	return s=="TAK";
}

int main() {
	int n,  k;
	cin >> n >> k;
	int x = solve(1, n);
	int a = solve(x+1, n);
	int b = solve(1, x-1);
	if(check(a, x)) cout << "2 " << x << " " << a << endl;
	else cout << "2 " << x << " " << b << endl;
}