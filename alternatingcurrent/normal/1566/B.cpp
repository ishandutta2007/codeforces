#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
string s;
int cnt0, cnt1;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> s;
		cnt0 = cnt1 = 0;
		int i = 0; 
		while(i < (int)s.size()){
			int j = i;
			while(j < (int)s.size() && s[j] == s[i])
				j++;
			if(s[i] == '0')
				cnt0++;
			else
				cnt1++;
			i = j; 
		}
		if(cnt0 == 0)
			cout << "0" << endl;
		else if(cnt0 == 1)
			cout << "1" << endl;
		else
			cout << "2" << endl;
	}
	return 0;
}