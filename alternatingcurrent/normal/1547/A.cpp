#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int xa, ya, xb, yb, xf, yf;
		cin >> xa >> ya >> xb >> yb >> xf >> yf;
		int dist = abs(xa - xb) + abs(ya - yb);
		if((xa == xb && xf == xa && (ya - yf) * (yb - yf) < 0) || (ya == yb && yf == ya && (xa - xf) * (xb - xf) < 0))
			dist += 2;
		cout <<dist << endl;
	}
	return 0;
}