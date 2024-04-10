#include <iostream>
#include <vector>
using namespace std;

string cmpl(const string &s){
	string ans;
	for(const char &c : s)
		ans.push_back(c == '*' ? '+' : '*');
	return ans;
}

int main(){
	int k;
	cin >> k;
	vector<string> st;
	st.push_back("+");
	while(k--){
		vector<string> nw;
		for(const string &s : st){
			nw.push_back(s + s);
			nw.push_back(s + cmpl(s));
		}
		st = nw;
	}
	for(string &s : st)
		cout << s << endl;
}