#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const int maxn = 1e5 + 100;
int a[maxn];
int main (){
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max (mx, a[i]);
	}
	int tot = 0;
	for (int i = 1; i <= n; i++)
		tot += mx - a[i];
	cout << tot << endl;
}