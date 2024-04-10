# include <bits/stdc++.h>

using namespace std;

int main(){
	double h;
	double l;
	cin >> h >> l;
	cout << setprecision(10) << (((h*h+l*l))/(2*h))-h;
	return 0;
}