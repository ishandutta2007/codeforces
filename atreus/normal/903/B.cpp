#include <bits/stdc++.h>

using namespace std;

vector <string> v;

int main (){
	ios_base::sync_with_stdio(false);
	int h, a, c, h2, a2;
	cin >> h >> a >> c >> h2 >> a2;
	while (h2 > 0){
		if (a >= h2){
			v.push_back("STRIKE");
			break;
		}
		if (h <= a2){
			v.push_back("HEAL");
			h += c;
			h -= a2;
		}
		else {
			v.push_back("STRIKE");
			h2 -= a;
			h -= a2;
		}
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}