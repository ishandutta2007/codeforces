#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000 * 1000 + 10;

int n, tmp, out;
int ans[MAXN];
string s;

stack<char> st;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	getline(cin, s);
	n=s.size();
	for (int i=0; i<n; i++){
		if (!st.empty() && st.top()==s[i]){
			st.pop();
		}
		else{
			st.push(s[i]);
		}
	}
	if (st.empty()){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	
	return 0;
}