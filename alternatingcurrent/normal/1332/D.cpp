#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int val;
	scanf("%d", &val);
	if(val == 0){
		cout << "1 1" << endl << "1" << endl;
		return 0;
	}
	int pw = 1 << 20;
	while(!(val & pw)) pw >>= 1;
	pw <<= 1;
	cout << "2 3" << endl;
	cout << pw + val << " " << pw << " " << pw << endl;
	cout << val << " " << pw + val << " " << val << endl;
	return 0;
}