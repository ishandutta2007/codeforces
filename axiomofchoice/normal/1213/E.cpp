#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2;
string s;
int n;
string work1(char a,char b,char c,int nn){
	string ss="";
	for(int i=0;i<nn;i++)ss+=a,ss+=b,ss+=c;
	return ss;
}
string work2(char a,char b,char c,int nn){
	string ss="";
	for(int i=0;i<nn;i++)ss+=a,ss+=b;
	for(int i=0;i<nn;i++)ss+=c;
	return ss;
}
string work3(char a,char b,char c,int nn){
	string ss="";
	for(int i=0;i<nn;i++)ss+=c;
	for(int i=0;i<nn;i++)ss+=a,ss+=b;
	return ss;
}
void work(){
	int a,b,c;
	for(a='a';a<='c';a++)
	for(b='a';b<='c';b++)if(a!=b)
	for(c='a';c<='c';c++)if(a!=c && b!=c){
		s=work1(a,b,c,2);
		if(s.find(s1)==-1 && s.find(s2)==-1){
			cout<<"YES"<<endl;
			cout<<work1(a,b,c,n)<<endl;
			return;
		}
		s=work2(a,b,c,2);
		if(s.find(s1)==-1 && s.find(s2)==-1){
			cout<<"YES"<<endl;
			cout<<work2(a,b,c,n)<<endl;
			return;
		}
		s=work3(a,b,c,2);
		if(s.find(s1)==-1 && s.find(s2)==-1){
			cout<<"YES"<<endl;
			cout<<work3(a,b,c,n)<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	cin>>s1>>s2;
	work();
	return 0;
}