#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	cout << "4\n";
	cout << "R 2\n";
	n += n-2;
	cout << "L 2\n";
	n ++;
	cout << "R 2\n";
	n += n-2;
	cout << "R " << n-1 << '\n';
	
}