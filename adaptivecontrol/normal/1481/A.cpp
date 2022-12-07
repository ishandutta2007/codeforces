#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int x,y,xa=0,ya=0;
		string s;
		cin>>x>>y>>s;
		for(int i=0;i<s.size();i++){
			if(x>0&&s[i]=='R')xa++;
			if(x<0&&s[i]=='L')xa++;
			if(y>0&&s[i]=='U')ya++;
			if(y<0&&s[i]=='D')ya++;
		}
		if(xa>=fabs(x)&&ya>=fabs(y))
			cout<<"YEs\n";
		else
			cout<<"No\n";
	}
}