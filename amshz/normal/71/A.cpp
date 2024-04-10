# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector <string> a;
	string q;
	for (int i=0; i<n; i++){
		cin >> q;
		a.push_back(q);
	}
	for (int i=0; i<n; i++){
		if (a[i].size() > 10){
			cout << a[i][0] << a[i].size()-2 << a[i][a[i].size()-1] << endl;
		}
		else{
			cout << a[i] << endl;
		}
	}
}