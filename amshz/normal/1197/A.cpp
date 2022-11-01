# include <iostream>
# include <vector>
# include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	int m;
	int mx1;
	int mx2;
	vector < vector < int > > a;
	for (int i=0; i<n; i++){
		cin >> m;
		vector <int> b(m);
		for (int j=0; j<m; j++){
			cin >> b[j];
		}
		a.push_back(b);
	}
	for (int i=0; i<n; i++){
		mx1 = 0;
		mx2 = 0;
		for (int j=0; j<a[i].size(); j++){
			if (a[i][j] > mx1){
				mx2 = mx1;
				mx1 = a[i][j];
			}
			else if (a[i][j] > mx2){
				mx2 = a[i][j];
			}
		}
		mx2 -= 1;
		m = a[i].size()-2;
		if (mx2 < m){
			cout << mx2 << endl;
		}
		else{
			cout << m << endl;
		}
	}
	return 0;
}