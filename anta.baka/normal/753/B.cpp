#include <bits/stdc++.h>

using namespace std;


int main() {
	string s = "0000";
	for(int i = 0; i < 4; i++) {
		int z = -1, c;
		for(int j = 0; j < 10; j++) {
			s[i] = j + '0';
			cout << s << "\n";
			cout.flush();
			int a, b;
			cin >> a >> b;
			if(a > z)
				z=a,c=j;
			if(a==4)
				return 0;
		}
		s[i]=c+'0';
	}
}