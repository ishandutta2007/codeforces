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
	for (int i = 0; i <= n / 1234567; i ++){
		for (int j = 0; j <= (n - i * 1234567) / 123456; j++){
			if ((n - i * 1234567 - j * 123456) % 1234 == 0)
				cur = true;
		}
	}
	if (cur)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}