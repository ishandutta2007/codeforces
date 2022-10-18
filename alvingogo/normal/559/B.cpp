#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

string sml(string s){
	if(s.length()%2==1){
		return s;
	}
	string a,b;
	string c="",d="";
	for(int i=0;i<s.length()/2;i++){
		c+=s[i];
	}
	for(int i=s.length()/2;i<s.length();i++){
		d+=s[i];
	}
	a=sml(c);
	b=sml(d);
	if(a<b){
		return a+b;
	}
	else{
		return b+a;
	}
}
int main(){
	string a,b;
	cin >> a >> b;
	if(sml(a)==sml(b)){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
	return 0;
}