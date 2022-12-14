
#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string n;
	int ans = 0;
	cin >> n;
	if (n[0] > '1'){
		cout << pow(2, n.size()) - 1 << endl;
		return 0;
	}
	for (int i = 0; i < n.size(); i++)
		if (n[i] > '1'){
			for (int j = i; j < n.size(); j++)
				n[j] = '1';
			break;
		}
	for (int i = 0; i < n.size(); i++){
		if (n[i] > '1'){
			ans += pow(2, n.size() - i);
			break;
		}
		if (n[i] == '1'){
			ans += pow(2, n.size() - i - 1);
		}
	}
	cout << ans << endl;
}