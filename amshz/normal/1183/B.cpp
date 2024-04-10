# include <bits/stdc++.h>

using namespace std;

const int xn = 2e2+10;
int a[xn];

int main(){
	int qq;
	cin >> qq;
	while (qq--){
		int n, k;
		cin >> n >> k;
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a, a+n);
		int l1 = a[0]-k, r1 = a[0]+k, l2 = a[n-1]-k, r2 = a[n-1]+k;
		//cout << "ans : ";
		if (r1 < l2){
			cout << -1 << endl;
		}
		else{
			cout << r1 << endl;
		}
	}
}