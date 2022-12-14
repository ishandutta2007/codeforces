#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
ll b[20], a[20];
ll p (int idx){
	for (int i = 0; i < 14; i++)
		b[i] = a[i];
	for (int i = idx + 1; i < 14; i++)
		b[i] += a[idx] / 14 + ((a[idx] % 14) >= i - idx);
	for (int i = 0; i < idx; i++)
		b[i] += a[idx] / 14 + ((a[idx] % 14) >= i + 14 - idx);
	b[idx] = a[idx] / 14;
	ll tot = 0;
//	cout << idx << " = ";
	for (int i = 0; i < 14; i++){
//		cout << b[i] << " ";
		if (b[i] % 2 == 0)
			tot += b[i];
	}
//	cout << endl;
	return tot;
}

int main (){
	for (int i = 0; i < 14; i++)
		cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < 14; i++){
		ans = max (ans, p(i));
	}
	cout << ans << endl;
}