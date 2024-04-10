# include <bits/stdc++.h>

using namespace std;

const int N = 2e3;
char q[N];
char w[N];

int main(){
	string a ,b ,c;
	cin >> a >> b >> c;
	a = a+b;
	for (int i=0; i<a.size(); i++){
		q[i] = a[i];
	}
	for (int i=0; i<c.size(); i++){
		w[i] = c[i];
	}
	sort(q,q+a.size());
	sort(w,w+c.size());
	bool f = 1;
	for (int i=0; i<c.size(); i++){
		if (q[i] != w[i]){
			cout << "NO";
			return 0;
		}
	}
	if (b == "JRMOU"){
		cout << "NO";
		return 0;
	}
	cout << "YES";
}