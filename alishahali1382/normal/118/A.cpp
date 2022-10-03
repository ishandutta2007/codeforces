#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string s;
int n;

string lower(string s){
	string t="";
	for (int i=0; i<n; i++){
		if ('A'<=s[i] && s[i]<='Z'){
			t+=(s[i]+'a'-'A');
		}
		else{
			t+=s[i];
		}
	}
	return t;
}

int vowel(char s){
	return (s=='a' || s=='o' || s=='y' || s=='e' || s=='u' || s=='i');
}

int main(){
	getline(cin, s);
    n=s.size();
    s=lower(s);
    string t="";
    for (int i=0;i<n;i++){
    	if (vowel(s[i])){
            continue;
        }
        else{
            t=(t+'.')+s[i];
        }
    }
    cout<<t<<endl;
}