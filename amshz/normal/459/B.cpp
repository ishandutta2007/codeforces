# include <bits/stdc++.h>
 
using namespace std;
 
const long long int xn = 1e6;
long long int a[xn];
 
int main(){
	long long int n;
	cin >> n;
	long long int mx ,mn;
	mx = 0;
	mn = 1e12;
	long long int t ,t2;
	t = 0;
	t2 = 0;
	for (long long int i=0; i<n; i++){
		cin >> a[i];
		if (a[i] >= mx){
			if (a[i] > mx){
				mx = a[i];
				t = 0;
			}
			t += 1;
		}
		if (a[i] <= mn){
			if (a[i] < mn){
				mn = a[i];
				t2 = 0;
			}
			t2 += 1;
		}
	}
	if (mx-mn == 0){
		t = (t2*(t2-1))/2;
		t2 = 1;
	}
	cout << mx-mn << ' ' << t*t2;
	return 0;
}