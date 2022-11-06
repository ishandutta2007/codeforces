#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

string s;

int main(){
	cin >> s;
	int p = -1;
	string t = "heidi";
	for(auto &i : t){
		p++;
		while(p < s.size() && s[p] != i) p++;
		if(p == s.size()){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}