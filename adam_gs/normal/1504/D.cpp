#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=107;
int T[LIM][LIM], bx, by, cx, cy=1, n;
void nastbiale(int k) {
	cout << k << " " << bx+1 << " " << by+1 << endl;
	by+=2;
	if(by>=n) {
		++by;
		++bx;
		by%=2;
		if(bx==n) bx=-1;
	}
}
void nastczarne(int k) {
	cout << k << " " << cx+1 << " " << cy+1 << endl;
	cy+=2;
	if(cy>=n) {
		++cy;
		++cx;
		cy%=2;
		if(cx==n) cx=-1;
	}
}
int main() {
	cin >> n;
	rep(i, n) rep(j, n) {
		int x;
		cin >> x;
		if(x==1) {
			if(cx!=-1) nastczarne(2);
			else nastbiale(3);
		} else if(x==2) {
			if(bx!=-1) nastbiale(1);
			else nastczarne(3);
		} else {
			if(bx!=-1) nastbiale(1);
			else nastczarne(2);
		}
	}
}