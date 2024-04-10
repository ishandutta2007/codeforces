#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

set<char> st;
string s;

int main(){
	getline(cin, s);
	for (int i=1; i<s.size(); i++){
		if (s[i]==',' || s[i]=='}'){
			st.insert(s[i-1]);
		}
	}
	st.erase('{');
	cout<<st.size()<<endl;
	return 0;
}