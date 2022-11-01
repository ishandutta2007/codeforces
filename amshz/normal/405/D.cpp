# include <bits/stdc++.h>

using namespace std;

const int xn = 1e6+10;
int a[xn];
int b[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
		if (a[i] > 1e6/2)
			b[int(1e6+1-a[i])] += 10;
		else
			b[a[i]] += 1;
	}
	vector <int> c;
	stack <int> d;
	for (int i=1; i<=1e6/2; i++)
		if (b[i] == 0) d.push(i);
	for (int i=1; i<=1e6/2; i++){
		if (b[i] == 1) c.push_back(1e6+1-i);
		else if (b[i] == 10) c.push_back(i);
		else if (b[i] == 11) c.push_back(d.top()), c.push_back(1e6+1-d.top()), d.pop();
	}
	cout << c.size() << endl;
	for (int i=0; i<c.size(); i++) cout << c[i] << ' ';
	return 0;
}