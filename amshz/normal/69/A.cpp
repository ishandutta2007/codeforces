# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector <int> x;
	vector <int> y;
	vector <int> z;
	int q ,w ,e;
	for (int i=0; i<n; i++){
		cin >> q >> w >> e;
		x.push_back(q);
		y.push_back(w);
		z.push_back(e);
	}
	int mx = 0;
	int my = 0;
	int mz = 0;
	for (int i=0; i<n; i++){
		mx += x[i];
		my += y[i];
		mz += z[i];
	}
	if (mx == 0 and my == 0 and mz == 0){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}