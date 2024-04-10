/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

bool isTriangle(int a, int b, int c){
	int m = max(a, max(b, c));
	return (m < (a + b + c - m));
}

bool isLine(int a, int b, int c){
	int m = max(a, max(b, c));
	return (m == (a + b + c - m));
}

int main(){
	//freopen("a.in", "r", stdin); freopen("a.out","w",stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (isTriangle(a, b, c) || isTriangle(a, b, d) || isTriangle(a, c, d) || isTriangle(b, c, d)){
		cout << "TRIANGLE";
	}else if (isLine(a, b, c) || isLine(a, b, d) || isLine(a, c, d) || isLine(b, c, d)){
		cout << "SEGMENT";
	}else{
		cout << "IMPOSSIBLE";
	}
}