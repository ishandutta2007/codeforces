#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
string ask(int x, int y) {
	cout << "? " << x << " " << y << endl;
	string ans;
	cin >> ans;
	return ans;
}
void out(int x) {
	cout << "! " << x << endl;
}
int start() {
	string x;
	cin >> x;
	return x == "start";
}
void solve(){
	string x = ask(0, 1);
	if(x == "x") {
		out(1);
		return;
	}
	x = ask(1, 2);
	if(x == "x") {
		out(2);
		return;
	}
	int d = 2;
	while(ask(d, d * 2) == "y") {
		d *= 2;
	}
	int l = d, r = d * 2;
	while(l + 1< r) {
		int mid = (l + r)/2;
		x = ask(r, mid);
		if(x == "y") {
			l = mid;
		}else {
			r = mid;
		}
	}
	out(r);
}
int main(){
	while(start()) {
		solve();
	}

}