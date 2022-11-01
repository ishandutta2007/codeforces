# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
int a[xn];
int b[xn];

int main(){
	int n, m;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	cin >> m;
	for (int i=0; i<m; i++) cin >> b[i];
	bool f;
	int q;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			q = a[i]+b[j];
			f = 1;
			for (int k=0; k<n; k++){
				if (q == a[k]) f = 0;
			}
			for (int k=0; k<m; k++){
				if (q == b[k]) f = 0;
			}
			if (f){
				cout << a[i] << ' ' << b[j];
				return 0;
			}
		}
	}
}