#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string a, b;
	cin >> a >> b;
	string s;
	s += a[0];
	for (int i = 1; i < a.size(); i++){
		if (a[i] < b[0])
			s += a[i];
		else
			break;
	}
	s += b[0];
	cout << s << endl;
}