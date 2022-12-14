#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
int wenhao[2];
int num[2];
string s;
int len;
int score(int n){
	return n*2-9;
}
void leftplus(){
	if(wenhao[0]>0)wenhao[0]--,num[0]+=score(9);
	else wenhao[1]--,num[1]+=score(0);
}
void rightplus(){
	if(wenhao[1]>0)wenhao[1]--,num[1]+=score(9);
	else wenhao[0]--,num[0]+=score(0);
}
void cout1(){
	cout<<"Bicarp"<<endl;
}
void cout2(){
	cout<<"Monocarp"<<endl;
}
int main(){
	//ios_base::sync_with_stdio(false);
	cin>>len;
	cin>>s;
	rep(i,0,len){
		if(s[i]=='?');
		else num[i>=len/2]+=score(s[i]-'0');
	}
	if(num[0]==num[1])cout1();
	else cout2();
	return 0;
}