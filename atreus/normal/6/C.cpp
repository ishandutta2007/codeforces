#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int bob = 0, alice = 0, t1 = 0, t2 = 0, l = 0, r = n - 1;
	while (r >= l){
		if (t1 <= t2){
			alice ++;
			t1 += a[l];
			l ++;
		}
		else {
			bob ++;
			t2 += a[r];
			r --;
		}
	}
	cout << alice << " " << bob << endl;
}