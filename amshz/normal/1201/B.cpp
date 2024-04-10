# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
long long int a[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long int s = 0;
	for (int i=0; i<n-1; i++){
		s += a[i];
	}
	if (s%2 == a[n-1]%2 and s >= a[n-1]){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}