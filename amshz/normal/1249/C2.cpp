# include <bits/stdc++.h>

using namespace std;

const int xn = 1e4+10;

string fn1(long long n){
	string a = "";
	while (n){
		if (n%3 == 0) a += '0';
		else if (n %3 == 1) a += '1';
		else a += '2';
		n /= 3;
	}
	reverse(a.begin(), a.end());
	return a;
}

int main(){
	int q;
	cin >> q;
	while (q--){
		long long n;
		cin >> n;
		string a = fn1(n);
		bool fl1 = 0;
		for (int i=0; i<a.size(); i++) if (a[i] == '2') fl1 = 1;
		if (fl1 == 0){
			cout << n << endl;
			continue;
		}
		int p = -1;
		for (int i=0; i<a.size(); i++){
			if (a[i] == '0') p = i;
			if (a[i] == '2') break;
		}
		if (p == -1){
			long long ans = 1;
			for (int i=0; i<a.size(); i++) ans *= 3;
			cout << ans << endl;
			continue;
		}
		else{
			string c = "";
			long long ans = 0;
			for (int i=0; i<p; i++) c += a[i];
			c += '1';
			for (int i=p+1; i<a.size(); i++) c += '0';
			for (int i = 0; i < c.size(); i++){
				ans *= 3;
				if (c[i] == '1') ans++;
			}
			cout << ans << endl;
		}
	}
}