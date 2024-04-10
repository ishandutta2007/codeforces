# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
string ans[xn];

int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		string a, b;
		cin >> a >> b;
		bool fl2 = 0;
		for (int j=0; j<a.size(); j++){
			bool fl1 = 0;
			for (int k=0; k<b.size(); k++){
				if (a[j] == b[k]){
					fl1 = 1;
					break;
				}
			}
			if (fl1){
				fl2 = 1;
				break;
			}
		}
		if (fl2) ans[i] = "YES";
		else ans[i] = "NO";
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
	return 0;
}