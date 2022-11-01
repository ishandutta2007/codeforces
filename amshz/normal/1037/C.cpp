# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	string a ,b;
	cin >> a >> b;
	int t = 0;
	int lx = 0;
	for (int i=0; i<n; i++){
		if (a[i] != b[i]){
			t += 1;
			if (i-lx == 1 and a[i] != a[lx] and t > 1){
				t -= 1;
				lx = 0;
			}
			else{
				lx = i;
			}
		}
	}
	cout << t;
	return 0;
}