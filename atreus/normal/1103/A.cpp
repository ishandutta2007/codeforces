/**
 *    author:  Atreus
 *    created: 22.01.2019
 **/
#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;


int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int now0 = 1, now1 = 1;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '0'){
			cout << now0 << " " << 1 << endl;
			if (now0 == 1)
				now0 = 3;
			else
				now0 = 1;
		}
		else{
			cout << now1 << " " << 3 << endl;
			now1 ++;
			if (now1 == 5)
				now1 = 1;
		}
	}
}