#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>

using namespace std;

const int maxn = 50 + 50;
long long a[maxn], prz[maxn], num[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	long long n, pnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 5; i++)
		cin >> prz[i];
	for (int i = 0; i < n; i++){
		pnt += a[i];
		for (int j = 4; j >= 0; j--){
			num[j] += pnt / prz[j];
			pnt %= prz[j];
		}
	}
	for (int i = 0; i < 5; i++)
		cout << num[i] << " ";
	cout << endl << pnt << endl;
}