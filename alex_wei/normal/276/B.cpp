#include<bits/stdc++.h>
using namespace std;
string s;
int buc[26],odd; 
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)buc[s[i]-'a']++;
	for(int i=0;i<26;i++)odd+=buc[i]&1;
	cout<<(odd<2?"First":odd%2?"First":"Second");
    return 0;
}