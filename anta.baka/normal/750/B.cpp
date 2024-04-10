#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int h = 10000;
	for(int i = 0; i < n; i++) {
		int l;
		string dir;
		cin >> l >> dir;
		if(h == 10000 && dir != "South")
			return cout << "NO",0;
		if(h == -10000 && dir != "North")
			return cout << "NO",0;
		if(dir == "South" && h - l < -10000)
			return cout << "NO",0;
		if(dir == "North" && h + l > 10000)
			return cout << "NO",0;
		if(dir == "South")
			h -= l;
		if(dir == "North")
			h += l;
	}
	if(h != 10000)
	    cout<<"NO";
	else cout << "YES";
}