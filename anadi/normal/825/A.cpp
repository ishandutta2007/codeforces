#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

int xd;
string s;

int main(){
	cin >> xd;
	cin >> s;
	s = s + '0';
	int res = 0, cur = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '1')
			++cur;
		else{
			res *= 10;
			res += cur;
			cur = 0;
		}
	}
	
	cout << res;
	return 0;
}