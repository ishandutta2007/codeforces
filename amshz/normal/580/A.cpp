# include <iostream>
# include <string>
# include <vector>

using namespace std;

const int xn = 1e5+10;
int a[xn];

int main(){
	int n;
	cin >> n;
	int t = 1;
	int mx = 0;
	for (int i=0; i<n; i++){
		cin >> a[i];
		if (i > 0){
			if (a[i] >= a[i-1]){
				t += 1;
			}
			else{
				if (t > mx){
					mx = t;
				}
				t = 1;
			}
		}
	}
	if (t > mx){
		mx = t;
	}
	cout << mx;
	return 0;
}