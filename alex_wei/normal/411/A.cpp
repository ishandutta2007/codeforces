#include<bits/stdc++.h>
using namespace std;
string s;
int num,dx,xx;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')num=1;
		if(s[i]<='Z'&&s[i]>='A')dx=1;
		if(s[i]<='z'&&s[i]>='a')xx=1;
	}
	if(num&&dx&&xx&&s.size()>=5)cout<<"Correct";
	else cout<<"Too weak"; 
	return 0;
}