#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	set<int> a,b;
	for(int i=0;i+1<s.size();i++){
		if(s[i]=='A'&&s[i+1]=='B') a.insert(i);
		else if(s[i]=='B'&&s[i+1]=='A') b.insert(i);
	}
	bool flag=false;
	for(auto x:a){
		if(b.size()>2||b.size()>(b.count(x+1)+b.count(x-1))) flag=true; 
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}