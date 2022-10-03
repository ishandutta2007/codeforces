#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000 * 1000 + 10;


int n, ans, tmp;

string s;

stack<int> st;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	getline(cin, s);
	n=s.size();
	for (int i=0; i<n; i++){
		if (s[i]=='<') tmp=1;
		if (s[i]=='(') tmp=2;
		if (s[i]=='{') tmp=3;
		if (s[i]=='[') tmp=4;
		if (s[i]=='>') tmp=-1;
		if (s[i]==')') tmp=-2;
		if (s[i]=='}') tmp=-3;
		if (s[i]==']') tmp=-4;
		
		if (tmp>0){
			st.push(tmp);
			continue ;
		}
		if (st.empty()){
			cout<<"Impossible"<<endl;
			return 0;
		}
		if (st.top()+tmp) ans++;
		st.pop();
	}
	if (!st.empty()){
		cout<<"Impossible"<<endl;
		return 0;		
	}
	cout<<ans<<endl;
	return 0;
}