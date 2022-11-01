# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

# define push_back pb;

const int xn = 1e2+10;

int num[xn];

ll a, b, c, d, e, cnt, flag, x, y, z, t, ans;

int main(){
	int q;
	cin >> q;
	while (q--){
		cin >> a;
		for (int i = 0; i < a; ++i)	cin >> num[i];
		int c1 = 0, c2 = 0, c3 = 0;
		for (int i=0; i<a; i++){
			if (num[i] % 3 == 0) c3++;
			else if (num[i] % 3 == 1) c1++;
			else c2++;
		}
		x = min(c1, c2);
		cout << c3 + x + (c1-x)/3 + (c2-x)/3 << endl;
	}
}