# include<iostream>
# include<vector>
# include<string>

using namespace std;

int main(){
	int n;
	cin >> n;
	int m;
	vector <int> a;
	int q;
	for (int i=0; i<n; i++){
		cin >> q;
		a.push_back(q);
		m += a[i];
	}
	//cout << m;
	int s = 0;
	int mx = 0;
	int t = 0;
	while (s <= m/2){
		mx = 0;
		for (int i=0; i<n; i++){
			if (a[i]> a[mx]){
				mx = i;
			}
		}
		//cout << mx;
		s += a[mx];
		for (int i=mx+1; i<n; i++){
			a[i-1] = a[i];
		}
		n -= 1;
		//cout << n;
		//a.resize(a.size()-1);
		//cout << a.size();
		t += 1;
	}
	cout << t;
	return 0;
}