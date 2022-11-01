# include <bits/stdc++.h>

using namespace std;

int main(){
	long long t, n, a, b, q, ans;
	string s;
	cin >> t;
	bool f, f2;
	for (int i=0; i<t; i++){
		cin >> n >> a >> b >> s;
		q = 0;
		ans = (n)*a+(n+1)*b;
		f = 0;
		f2 = 1;
		for (int j=1; j<n; j++){
			if (s[j] == '0' and s[j-1] == '1'){
				q = 0;
				f = 1;
			}
			else if (s[j] == '0' and f){
				q += 1;
			}
			else if (s[j] == '1' and f){
				if (q*b < 2*a) ans += q*b;
				else ans += 2*a;
				q = 0;
			}
			if (s[j] == '1'){
				ans += b;
				if (s[j-1] == '0') ans += b;
			}
			if (s[j] == '1' and f2) ans += 2*a, f2 = 0;
		}
		cout << ans << endl;
	}
}