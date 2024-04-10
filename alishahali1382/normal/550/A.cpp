#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	int n=s.size();
	int tmp=0;
	for (int i=1; i<n; i++){
		if (tmp==0 && s[i]=='B' && s[i-1]=='A'){
			tmp++;
			i++;
		}
		else if (tmp==1 && s[i]=='A' && s[i-1]=='B'){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	tmp=0;
	for (int i=1; i<n; i++){
		if (tmp==0 && s[i-1]=='B' && s[i]=='A'){
			tmp++;
			i++;
		}
		else if (tmp==1 && s[i-1]=='A' && s[i]=='B'){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}