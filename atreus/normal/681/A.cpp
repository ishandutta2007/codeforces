#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

int main (){
	int n;
	bool cur = false;
	cin >> n;
	for (int i = 0; i < n; i++){
		string a;
		int b, c;
		cin >> a >> b >> c;
		if (b >= 2400 && c > b)
			cur = true;
	}
	if (cur)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}