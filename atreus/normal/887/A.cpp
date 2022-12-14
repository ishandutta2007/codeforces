#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int inx;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1'){
			inx = i + 1;
			break;
		}
	int cnt = 0;
	for (int i = inx; i < s.size(); i++){
		if (s[i] == '0')
			cnt ++;
	}
	if (cnt >= 6)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}