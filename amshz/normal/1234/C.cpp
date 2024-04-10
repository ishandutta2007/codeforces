# include <bits/stdc++.h>

using namespace std;

const int xn = 1e4+10;

string ans[xn];
string a[5];

int main(){
	int t;
	cin >> t;
	bool fl1, fl2;
	for (int ii=0; ii<t; ii++){
		int n;
		cin >> n;
		cin >> a[0] >> a[1];
		pair <int,int> p;
		p.first = 0;
		p.second = 0;
		fl1 = 0;
		while (true){
			//cout << fl1 << ' ' << p.first << ' ' << p.second << endl;
			if (p.second == n) break;
			if ((a[p.first][p.second] == '1' or a[p.first][p.second] == '2' )and fl1 == 1){
				p.first = 0;
				break;
			}
			fl2 = 0;
			if (a[p.first][p.second] == '1' or a[p.first][p.second] == '2') p.second++, fl2 = 0;
			else if (fl1) p.second++, fl2 = 0;
			else{
				if (p.first == 1) p.first = 0;
				else p.first = 1;
				fl2 = 1;
			} //p.first = 1-p.first, fl2 = 1;
			fl1 = fl2;
		}
		if (p.first == 1) ans[ii] = "YES";
		else ans[ii] = "NO";
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
}