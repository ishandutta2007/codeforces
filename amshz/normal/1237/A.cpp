# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
int a[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int t = 0;
	int s = 0;
	//cout << endl;
	for (int i=0; i<n; i++){
		if (a[i]%2 == 0) cout << a[i]/2 << endl;
		else{
			if (a[i] > 0 and t >= 0) cout << a[i]/2+1 << endl, t--, s += a[i]/2+1;
			else if (a[i] < 0 and t >= 0) cout << a[i]/2 << endl, t--, s += a[i]/2-1;
			else if (a[i] > 0 and t < 0) cout << a[i]/2 << endl, t++, s += a[i]/2;
			else if (a[i] < 0 and t < 0) cout << a[i]/2-1 << endl, t++, s += a[i]/2-1;
		}
	}
	//cout << "s : " <<  s << endl;
}