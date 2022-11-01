# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int t = 0;
	vector <int> a;
	int q;
	for (int i=0; i<n; i++){
		cin >> q;
		a.push_back(q);
	}
	for (int i=0; i<n; i++){
		if (a[i] >= a[m-1] and a[i] > 0){
			t += 1;
		}
	}
	cout << t;
	return 0;
}