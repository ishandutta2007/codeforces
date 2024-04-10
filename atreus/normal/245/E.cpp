#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int in = 0, out = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '+'){
			in ++;
			out --;
		}
		else {
			in --;
			out ++;
		}
		if (in == -1)
			in ++;
		if (out == -1)
			out ++;
	}
	cout << in + out << endl;
}