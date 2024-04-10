# include <bits/stdc++.h>

using namespace std;

const int xn = 5e1+10;
string a[xn], b[xn];

int main(){
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		//cout << "ans : ";
		if (n == 0){
			bool fl1 = 0;
			for (int i=0; i<a[0].size(); i++)
				if (a[0][i] != a[0][a[0].size()-i-1]) fl1 = true;
			if (fl1) cout << 0 << endl;
			else cout << 1 << endl;
			continue;
		}
		int tz = 0;
		int tf = 0;
		int s = 0, z = 0;
		for (int i=0; i<n; i++){
			int y = 0;
			for (int j=0; j<a[i].size(); j++) 
				if (a[i][j] == '1') y++;
			b[i] = y;
			if (a[i].size()%2 == 0) tz++;
			else tf++;
			s += y;
		}
		//
		for (int i=0; i<n; i++){
			if (a[i].size()%2 == 1) z++;
		}
		for (int i=0; i<n; i++){
			if (s == 0) break;
			if (a[i].size()%2 == 0 and a[i].size() > s and s%2 == 0) s = 0;
			else if (a[i].size()%2 == 0 and a[i].size() > s and s%2 == 1) s = 1;
			else  if (a[i].size()%2 == 0 and a[i].size() <= s) s -= a[i].size();
			
			if (a[i].size()%2 == 1){
				if (s < a[i].size()) s = 0;
				else{
					s -= a[i].size();
					s++;
					//z++;
				}
			}
		}
		if (s > z) cout << n-1 << endl;
		else cout << n << endl;
		//
		/*
		bool fl1 = false;
		for (int i=0; i<n; i++){
			if (a[i].size()%2 == 1) fl1 = true;
		}
		if (fl1 == false and s%2 == 1) cout << n-1 << endl;
		else cout << n << endl;
		*/
	}
}