#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

int a[20] = {2, 3, 4, 5, 7, 9, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49};

int main() {
	ifstream fin("tst.txt");
	ofstream fout("tst.txt");
	int cnt = 0;
	string s;
	for (int i = 0; i < 19; i++){
		cout << a[i] << endl;
		cin >> s;
		if (s == "yes")
			cnt ++;
	}
	if (cnt > 1)
		return cout << "composite" << endl, 0;
	cout << "prime";
}