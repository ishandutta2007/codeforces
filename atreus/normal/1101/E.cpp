/**
 *    author:  Atreus
 *    created: 11.01.2019 18:52:50      
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	int mxx = 0, mxy = 0;
	for (int i = 0; i < q; i++){
		char type;
		cin >> type;
		if (type == '+'){
			int x, y;
			cin >> x >> y;
			if (x > y)
				swap(x, y);
			mxx = max(mxx, x);
			mxy = max(mxy, y);
		}
		else{
			int h, w;
			cin >> h >> w;
			if (h > w)
				swap(h, w);
			if (h < mxx or w < mxy)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
}