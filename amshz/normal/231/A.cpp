# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	bool a ,b ,c;
	int t=0;
	int m;
	for (int i=0; i<n; i++){
		cin >> a >> b >> c;
		m = a+b+c;
		if (m > 1){
			t += 1;
		}
	}
	cout << t;
	return 0;
}