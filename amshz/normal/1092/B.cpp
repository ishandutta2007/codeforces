# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	int q;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (a[j] < a[i]){
				q = a[j];
				a[j] = a[i];
				a[i] = q;
			}
		}
	}
	int t = 0;
	for (int i=0; i<n; i+=2){
		t += a[i+1]-a[i];
	}
	cout << t;
	return 0;
}