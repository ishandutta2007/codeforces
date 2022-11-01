# include<iostream>
# include<string>
# include<vector>

using namespace std;
int a[10];
int main(){
	bool f;
	int t = 0;
	for (int i=0; i<4; i++){
		cin >> a[i];
		f = 1;
		for (int j=0; j<i; j++){
			if (a[i] == a[j]){
				f = 0;
				break;
			}
		}
		if (f == 1){
			t += 1;
		}
	}
	cout << 4-t;
	return 0;
}