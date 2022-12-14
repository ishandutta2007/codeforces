#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

ld mnm[maxn], mxm[maxn], p[maxn], q[maxn];

ld equ(ld a, ld b, ld c){
	ld del = b * b - 4. * a * c;
	ld zer = 0.0;
	return (-b + sqrt(max(zer, del))) / (2. * a);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> mxm[i];
	for (int i = 1; i <= n; i++)
		cin >> mnm[i];
	ld Sp = 0, Sq = 0;
	for (int i = 1; i <= n; i++){
		ld a = Sq, b = Sp, x = 0, k = 0;
		x = mnm[i] + mxm[i];
		k = mxm[i];
		q[i] = equ(1, a - b - x, -a * x + k);
		p[i] = x - q[i];
		Sp += p[i], Sq += q[i];
	}
	for (int i = 1; i <= n; i++)
		cout << fixed << setprecision(8) << p[i] << " \n"[i == n];
	for (int i = 1; i <= n; i++)
		cout << fixed << setprecision(8) << q[i] << " \n"[i == n];
}