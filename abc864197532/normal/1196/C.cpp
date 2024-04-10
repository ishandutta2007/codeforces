#include <bits/stdc++.h>
using namespace std;
#define lli long long int


int main () {
	int t;
	cin >> t;
	for (int i=0;i<t;++i) {
		int n,left=-100000,right=100000,up=100000,down=-100000;
		cin >> n;
		bool is=true;
		for (int j=0;j<n;++j) {
			int x,y,a,b,c,d;
			cin >> x >> y >> a >> b >> c >> d;
			if (is) {
				if (a==0) {
					if (right<x) is=false;
					else if (left<x) left=x;
				} if (b==0) {
					if (down>y) is=false;
					else if (up>y) up=y;
				} if (c==0) {
					if (left>x) is=false;
					else if (right>x) right=x;
				} if (d==0) {
					if (up<y) is=false;
					else if (down<y) down=y;
				}
				if (right<left or up<down) is=false;
			}
		}
		if (is) cout << 1 << ' ' << left << ' ' << down << endl;
		else cout << 0 << endl;
	}
}