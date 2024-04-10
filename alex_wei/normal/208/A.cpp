#include<bits/stdc++.h>
using namespace std;
string s;
int pos,pos2;
int main()
{
	cin>>s;
	while(pos+3<=s.size()&&s[pos]=='W'&&s[pos+1]=='U'&&s[pos+2]=='B')pos+=3;
	pos2=s.size()-1;
	while(pos2>1&&s[pos2]=='B'&&s[pos2-1]=='U'&&s[pos2-2]=='W')pos2-=3;
	int pd=0;
	for(int i=pos;i<=pos2;){
		if(i+3<=pos2&&s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')pd=1,i+=3;
		else{
			if(pd)cout<<" ";
			cout<<s[i],i++;
			pd=0;
		}
	}
	return 0;
}