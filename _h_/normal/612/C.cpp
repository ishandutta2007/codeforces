#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	string s;
	cin >> s;
	int ans = 0;
	stack<char> st;
	for(char c : s){
		if(c=='('||c=='<'||c=='{'||c=='[')
			st.push(c);
		else {
			if(st.empty()){
				puts("Impossible");
				return 0;
			}
			++ans;
			char d = st.top();
			st.pop();
			if((d=='('&&c==')')
			||(d=='<'&&c=='>')
			||(d=='{'&&c=='}')
			||(d=='['&&c==']'))
				--ans;
		}
	}
	if(!st.empty())
		puts("Impossible");
	else
		cout << ans << endl;
}