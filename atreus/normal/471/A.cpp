#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int a[10];

bool f(int a, int b, int c, int d){
	if (a != b)
		return false;
	if (a != c)
		return false;
	if (a != d)
		return false;
	return true;
}

int main (){
	for (int i = 1; i <= 6; i++)
		cin >> a[i];
	sort (a + 1, a + 7);
	int k = 0;
	if (f(a[1], a[2], a[3], a[4])){
		if (a[5] == a[6])
			return cout << "Elephant" << endl, 0;
		else
			return cout << "Bear" << endl, 0;
	}
	if (f(a[5], a[2], a[3], a[4])){
		if (a[1] == a[6])
			return cout << "Elephant" << endl, 0;
		else
			return cout << "Bear" << endl, 0;
	}
	if (f(a[5], a[6], a[3], a[4])){
		if (a[1] == a[2])
			return cout << "Elephant" << endl, 0;
		else
			return cout << "Bear" << endl, 0;
	}
	cout << "Alien" << endl;
}