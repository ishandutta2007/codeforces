#include <iostream>
using namespace std;

int a[200000];
int b[200000];
int c[200000];
int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		b[i] = 0;
		c[i] = 0;
	}
	for(int i=0; i<n; i++){
		if(a[i] == 0){
			b[i] = 0;
		}
		else{
			if(i==0){
				b[i] = 1000000;
			}
			else{
				b[i] = b[i-1]+1;
			}
		}
	}
	for(int i=n-1; i>=0; i--){
		if(a[i] == 0){
			c[i] = 0;
		}
		else{
			if(i==n-1){
				c[i] = 1000000;
			}
			else{
				c[i] = c[i+1]+1;
			}
		}
	}
	for(int i=0; i<n; i++){
		cout << min(c[i], b[i]) << " " ;
	}
	cout << endl;
	return 0;
}