
// Problem : B. Dreamoon and WiFi
// Contest : Codeforces - Codeforces Round #272 (Div. 2)
// URL : https://codeforces.com/contest/476/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

string s1, s2;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s1 >> s2;
	int pos = 0;
	for(int i = 0; i<s1.size(); i++){
		pos += (s1[i] == '+' ? 1 : -1);
	}
	int tot = 0, des = 0;
	for(int m = 0; m<1<<s2.size(); m++){
		bool b = 1;
		int p = 0;
		for(int k = 0; k<s2.size(); k++){
			//cout << k << " " << s2[k] << " " << ((m>>k)&1) << "\n";
			//cout << (s2[k] == '+') << "\n";
			if(s2[k] == '+' && ((m>>k)&1) == 0){
				//cout << "here\n";
				b = 0;
			}
			if(s2[k] == '-' && ((m>>k)&1) == 1){
				b = 0;
			}
			p += 2*((m>>k)&1)-1;
		}
		//cout << m << " " << b << "\n";
		if(b){
			tot++;
			if(p == pos){
				des++;
			}
		}
	}
	cout << setprecision(13) << 1.0*des/tot << "\n";
}