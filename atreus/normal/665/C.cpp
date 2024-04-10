#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++){
		if (s[i] == s[i - 1]){
			for (int j = 0; j < 26; j++){
				if ((i == s.size() - 1 || s[i + 1] != j + 'a') && s[i - 1] != j + 'a'){
					s[i] = j + 'a';
					break;
				}
			}
		}
	}
	cout << s << endl;
}