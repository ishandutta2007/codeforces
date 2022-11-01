# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	//cout << f1(25,15);
	int n;
	cin >> n;
	vector <int> a(n);
	int mx = 0;
	int mn = 101;
	for (int i=0; i<n; i++){
		cin >> a[i];
		if (a[i] > mx){
			mx = a[i];
		}
		if (a[i] < mn){
			mn = a[i];
		}
	}
	if (mx == mn){
		cout << 0;
		return 0;
	}
	bool f = 1;
	int q;
	int m = -1;
	for (int i=1; i<mx; i++){
		f = 1;
		q = a[0]% i;
		for (int j=0; j<n; j++){
			if (a[j]%i != q){
				f = 0;
				break;
			}
			if (a[j]%i == q){
				q = a[j]%i;
			}
		}
		if (mx-mn <= i*2 and f){
			m = i;
			cout << m;
			return 0;
		}
	}
	cout << m;
	return 0;
}