# include <iostream>
# include <vector>
# include <string>

using namespace std;

const int N = 2e5+10;
int a[N];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	bool f = 0;
	for (int i=1; i<n; i++){
		if (a[i] < a[i-1]){
			f = 1;
		}
		if (f and a[i] > a[i-1]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}