# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
long long int t[xn];
long long int s[xn];
long long int p[xn];

int main(){
	int n;
	cin >> n;
	long long int q;
	for (long long int i=0; i<n; i++){
		cin >> t[i] >> s[i] >> p[i];
		q = s[i];
		if (p[i] < s[i])
			q = p[i];
		q = t[i]-q+1;
		cout << q << endl;
	}
	return 0;
}