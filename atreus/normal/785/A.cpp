#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main (){
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		if (s == "Tetrahedron")
			cnt += 4;
		if (s == "Cube")
			cnt += 6;
		if (s == "Octahedron")
			cnt += 8;
		if (s == "Dodecahedron")
			cnt += 12;
		if (s == "Icosahedron")
			cnt += 20;
	}
	cout << cnt << endl;
}