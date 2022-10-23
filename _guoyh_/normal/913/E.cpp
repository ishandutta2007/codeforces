# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 8;
int n;
string f[1 << MAXN][3];
string f1[1 << MAXN];
string s1;
void upd(string &a, string b){
	if (a.size() == 0 || b.size() < a.size() || (b.size() == a.size() && b < a)) a = b;
}
int main(){
	f[0x0F][2] = "x";
	f[0x33][2] = "y";
	f[0x55][2] = "z";
	for (int t = 1; t <= 20; t++){
		for (int i = 0; i < (1 << MAXN); i++){
			if (f[i][2].size()) upd(f[i ^ 0xFF][2], "!" + f[i][2]);
			for (int j = 0; j <= 2; j++){
				if (f[i][j].size()) upd(f[i][2], "(" + f[i][j] + ")");
			}
			for (int j = 0; j < (1 << MAXN); j++){
				for (int k1 = 0; k1 <= 2; k1++){
					for (int k2 = 0; k2 <= 2; k2++){
						if (!f[i][k1].size() || !f[j][k2].size()) continue;
						if (k1 >= 1 && k2 >= 1) upd(f[i & j][1], f[i][k1] + "&" + f[j][k2]);
						upd(f[i | j][0], f[i][k1] + "|" + f[j][k2]);
					}
				}
			}
		}
	}
	for (int i = 0; i < (1 << MAXN); i++){
		for (int j = 0; j <= 2; j++) upd(f1[i], f[i][j]);
		cerr << f1[i] << endl;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		cin >> s1;
		int nw = 0;
		for (int i = 0; i < 8; i++) if (s1[i] == '1') nw |= (1 << (7 - i));
		cout << f1[nw] << endl;
	}
	return 0;
}