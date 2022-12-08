#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int h,m;
string s;
int rev[256];

bool correct(string s){
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();++i)
	if(i!=2){
		if(rev[s[i]]==-1)return 0;
		s[i]=rev[s[i]];
	}
	int h1=(s[0]-'0')*10+s[1]-'0';
	int m1=(s[3]-'0')*10+s[4]-'0';
	return h1<h&&m1<m;
}

void next(string &s){
	int h1=(s[0]-'0')*10+s[1]-'0';
	int m1=(s[3]-'0')*10+s[4]-'0';
	++m1;
	if(m1==m){
		++h1;
		m1=0;
	}
	if(h1==h){
		h1=0;
	}
	s[0]=h1/10+'0';
	s[1]=h1%10+'0';
	s[3]=m1/10+'0';
	s[4]=m1%10+'0';
}

int main(){
	rev['0']='0';
	rev['1']='1';
	rev['2']='5';
	rev['3']=-1;
	rev['4']=-1;
	rev['5']='2';
	rev['6']=-1;
	rev['7']=-1;
	rev['8']='8';
	rev['9']=-1;
	cin>>T;
	while(T--){
		cin>>h>>m;
		cin>>s;
		while(!correct(s)){
			next(s);
		}
		cout<<s<<endl;
	}
}