# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	int t = 0;
	string q;
	for (int i=0; i<n; i++){
		cin >> q;
		if (q[1] == '+'){
			t += 1;
		}
		else{
			t -= 1;
		}
	}
	cout << t;
	return 0;
}