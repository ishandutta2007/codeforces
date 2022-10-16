#include<bits/stdc++.h>
using namespace std;
string s; 
int main()
{
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]==','){
			if(i<s.size()-1)cout<<", ";
			else cout<<",";
		}
		else if(s[i]=='.'){
			int j=i-1;
			while(j>-1&&s[j]==' ')j--;
			if(s[j]!=','&&i>0)cout<<" ";
			cout<<"...";
			i+=2;
		}
		else if(s[i]!=' '){
			int j=i+1;
			while(j<s.size()&&s[j]==' ')j++;
			if(s[j]<='9'&&s[j]>='0'&&j>i+1)cout<<s[i]<<" ",i=j-1;
			else cout<<s[i];
		}
	}
	return 0;
}