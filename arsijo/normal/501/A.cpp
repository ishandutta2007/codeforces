/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int count(int p, int t){
	double a = (double) (3 * p) / 10;
	double b = (double) p - (p / 250 * t);
	return max( (int) a, (int) b);
}

int main() {

	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int a1 = count(a, c);
	int a2 = count(b, d);
	if (a1 > a2){
		cout << "Misha";
	}else if (a1 < a2){
		cout << "Vasya";
	}else{
		cout << "Tie";
	}

}