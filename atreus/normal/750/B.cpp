#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

int main(){
	int n;
	cin >> n;
	int k = 0;
	bool ans = 1;
	for (int i = 0; i < n; i++){
		int l;
		string a;
		cin >> l >> a;
		if (a == "South"){
			if (k == 20000)
				ans = 0;
			k += l;
			if (k > 20000)
				ans = 0;
		}
		if (a == "North"){
			if (k == 0)
				ans = 0;
			k -= l;
			if (k < 0)
				ans = 0;
		}
		if ((a == "West" or a == "East") and (k == 0 or k == 20000))
			ans = 0;
	}
	if (ans and k == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}