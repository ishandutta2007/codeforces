# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
long long n[xn], m[xn], ans[xn];

int main(){
	long long t, q, w, s;
	cin >> t;
	bool f;
	for (int i=0; i<t; i++) cin >> n[i] >> m[i];
	for (int i=0; i<t; i++){
		vector <int> b;
		q = m[i]%10;
		w = q;
		f = 1;
		b.push_back(q);
		while (w != q or f){
			f = 0;
			w = w+q;
			w = w%10;
			b.push_back(w);
		}
		b.resize(b.size()-1);
		s = 0;
		for (int j=0; j<b.size(); j++){
			//cout << b[j] << ' ';
			s += b[j]*((n[i]/m[i])/b.size());
			if (n[i] >= m[i] and (n[i]/m[i]%b.size()) > j) s += b[j];
		}
		//cout << endl;
		ans[i] = s;
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
}