# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
int a[xn];

int main(){
	int q;
	cin >> q;
	while (q--){
		string a;
		cin >> a;
		string b = "", abc = "abcdefghijklmnopqrstuvwxyz";
		for (int i=0; i<26; i++){
			bool fl1 = 0;
			int t = 0;
			for (int j=0; j<a.size(); j++){
				if (a[j] == abc[i]) t++;
				else{
					if (t%2 == 1) fl1 = true;
					t = 0;
				}
			}
			if (t%2 == 1) fl1 = true;
			if (fl1) b += abc[i];
		}
		cout << b << endl;
	}
}