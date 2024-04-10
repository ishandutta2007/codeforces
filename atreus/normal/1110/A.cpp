/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int b, k;
	cin >> b >> k;
	for (int i = 0; i < k; i++)
		cin >> a[i];
	if (b % 2 == 0){
		if (a[k - 1] & 1)
			cout << "odd" << endl;
		else
			cout << "even" << endl;
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < k; i++)
		if (a[i] & 1)
			cnt ++;
	if (cnt & 1)
		cout << "odd" << endl;
	else
		cout << "even" << endl;
}