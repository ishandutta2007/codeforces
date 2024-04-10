# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n ,m;
	cin >> n >> m;
	n = n+m;
	int s = 1;
	for (int i=0; i<n; i++){
		s *= 2;
		s = s%998244353;
	}
	cout << s;
	return 0;
}