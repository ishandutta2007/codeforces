#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <fstream>

#define F first
#define S second
#define PB push_back
using namespace std;

const int maxn = 1e5 + 100;
int c[maxn], a[maxn];

int main(){
	int idx, h, n = 0;
	cin >> h;
	bool cur = false, iso = false;
	for (int i = 0; i <= h; i++){
		cin >> a[i];
		c[i] = a[i];
		n += a[i];
		if (a[i] > 1){
			if (cur){
				iso = 1;
				idx = i;
			}
			else
				cur = 1;
		}
		if (a[i] == 1)
			cur = 0;
	}
	if (!iso)
		return cout << "perfect" << endl, 0;
	cout << "ambiguous" << endl;
	int dad = 0, m = 0;
	for (int i = 0; i <= h; i++){
		m += a[i];
		if (i != idx)
			while (a[i] --)
				cout << dad << " ";
		else {
			while (a[i] > 1){
				cout << dad << " ";
				a[i] --;
			}
			cout << dad - 1 << " ";
		}
		dad = m;
	}
	cout << endl;
	dad = 0, m = 0;
	for (int i = 0; i <= h; i++){
		m += c[i];
		while (c[i] --)
			cout << dad << " ";
		dad = m;
	}
}