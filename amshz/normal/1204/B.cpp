# include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, a, b;
	cin >> n >> a >> b;
	long long s = pow(2,a)-1;
	s += n-a;
	cout << s << ' ';
	s = pow(2,b)-1;
	s += (n-b)*(pow(2,b-1));
	cout << s;
}