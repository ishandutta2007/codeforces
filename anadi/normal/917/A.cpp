#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

string s;

int main(){
	cin >> s; int res = 0;
	for(int i = 0; i < s.size(); ++i){
		bool ok = true;
		int mini = 0, maxi = 0;

		for(int j = i; j < s.size(); ++j){
			if(s[j] == '('){
				++mini;
				++maxi;
			}
			else if(s[j] == ')'){
				--mini;
				--maxi;

				if(mini < 0)
					mini += 2;
				if(maxi < 0)
					ok = false;
			}
			else{
				--mini;
				++maxi;
				
				if(mini < 0)
					mini += 2;
			}
			
			if(ok && mini == 0)
				++res;
		}
	}
	
	cout << res;
	return 0;
}