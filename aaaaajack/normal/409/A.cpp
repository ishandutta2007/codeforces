#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int i,x,y,a=0,b=0;
	for(i=0;i<s1.size();i+=2){
		if(s1[i]=='(') x=0;
		else if(s1[i]=='[') x=1;
		else x=2;
		if(s2[i]=='(') y=0;
		else if(s2[i]=='[') y=1;
		else y=2;
		if((x+1)%3==y) b++;
		else if((y+1)%3==x) a++;
	}
	if(a>b) cout<<"TEAM 1 WINS"<<endl;
	else if(a==b) cout<<"TIE"<<endl;
	else cout<<"TEAM 2 WINS"<<endl;
	return 0;
}