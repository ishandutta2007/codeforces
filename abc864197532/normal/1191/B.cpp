#include <iostream>
#include <vector> // vector
#include <algorithm> // sort
#include <math.h> // math
#include <map> // map
#include <string> // string
using namespace std;

bool same(string a,string b)  {
	if (a==b) return true;
	return false;
}

bool stair(string a,string b) {
	if (a[0]-b[0]==1 or b[0]-a[0]==1 or a[0]-b[0]==2 or b[0]-a[0]==2) {
		if (a[1]==b[1]) return true;
	}
	return false;
}

bool stair2(string a,string b,string c) {
	int aa[3];
	if (a[1]==b[1] and b[1]==c[1]) {
		aa[0]=a[0]-'0';
		aa[1]=b[0]-'0';
		aa[2]=c[0]-'0';
		sort(aa,aa+3);
		if (aa[2]-aa[1]==1 and aa[1]-aa[0]==1) return true;
	}
	return false;
}


int main () {
	string a,b,c;
	cin >> a >> b >> c;
	if (a==b and b==c) cout << 0 << endl;
	else if (same(a,b) or same(b,c) or same(c,a)) cout << 1 << endl;
	else if (stair2(a,b,c)) cout << 0 << endl;
	else if (stair(a,b) or stair(b,c) or stair(c,a)) cout << 1 << endl;
	else cout << 2 << endl;
}