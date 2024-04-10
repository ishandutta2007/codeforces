#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int T,t[200];
string s;
void go(int x){
	if(!x) return;
	go((x-1)/26);
	cout<<(char)((x-1)%26+65);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	for(int i=48;i<=57;++i)t[i]=1;
	while(T--){
		cin>>s;
		int cnt=0;
		for(int i=1;i<s.size();++i)if(t[s[i]]!=t[s[i-1]])++cnt;
		if(cnt==1){
			string q[2];
			q[0]="",q[1]="";
			int o=0;
			for(int i=0;i<s.size();++i){
				if(t[s[i]])o=1;
				q[o]+=s[i];
			}
			o=0;
			for(int i=0;i<q[0].size();++i)o=o*26+q[0][i]-64;
			cout<<"R"<<q[1]<<"C"<<o<<endl;
			continue;
		}
		string q[2];
		q[0]="",q[1]="";
		int o=-1;
		for(int i=0;i<s.size();++i){
			if(s[i]=='R'||s[i]=='C')++o;
			else q[o]+=s[i];
		}
		o=0;
		for(int i=0;i<q[1].size();++i)o=o*10+q[1][i]-48;
		go(o);
		cout<<q[0]<<endl;
	}
	return 0;
}