#include<bits/stdc++.h>
using namespace std;
string s;
int x,d;
char lar(char s){if(s>'Z')s-=32;return s;}
char sma(char s){if(s<='Z')s+=32;return s;}
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>'Z')x++;
		else d++;
	}
	for(int i=0;i<s.size();i++){
		if(d>x)cout<<lar(s[i]);
		else cout<<sma(s[i]);
	}
	return 0;
}