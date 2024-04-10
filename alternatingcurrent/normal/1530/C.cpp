#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[100100], b[100100];
int suma, sumb;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		rep(i, n)
			cin >> b[i];
		sort(a, a + n), sort(b, b + n);
		reverse(a, a + n), reverse(b, b + n);
		suma = 0, sumb = 0;
		int cnta = n - n / 4, cntb = n - n / 4;
		rep(i, cnta)
			suma += a[i];
		rep(i, cntb)
			sumb += b[i];
		if(suma >= sumb){
			cout << "0" << endl;
			continue;
		}
		for(int k = n + 1; k <= n + n + 100; k++){
			if(k % 4 == 0 && cnta)
				suma -= a[--cnta];
			suma += 100;
			if(k % 4 != 0 && cntb < n)
				sumb += b[cntb++];
			if(suma >= sumb){
				cout << k - n << endl;
				break;
			}
		}
	}
	return 0;
}