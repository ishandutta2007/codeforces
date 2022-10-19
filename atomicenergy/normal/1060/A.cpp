#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tot = 0;
	int no = 0;
	for(int i=0; i<n; i++){
		char x;
		cin >> x;
		if(x=='8') tot++;
		else no++;
	}
	cout << min(tot, (no+tot)/11);
	return 0;
}