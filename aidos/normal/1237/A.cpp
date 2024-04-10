#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int n;
int a[100100];
int b[100100];
int main () {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int s = 0;
	for(int i=0; i < n; i++) {
		if(a[i] % 2 == 0) {
			a[i]/=2;
		}else if(a[i] < 0){
			a[i] = abs(a[i]);
			a[i]/=2;
			a[i] *= -1;
			b[i]=-1;
		}else {
			a[i]/=2;
			b[i]=1;
		}
		//cout << a[i] << " " << b[i] << "\n";
		s += a[i];
	}
	for(int i = 0; i < n; i++) {
		if(abs(s) > abs(s+b[i])) {
			a[i] += b[i];
			s += b[i];
		}
		cout << a[i] << "\n";
	}
	//cout << s << "\n";
 	return 0;
}