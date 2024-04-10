#include<bits/stdc++.h>
using namespace std;
//There are only two possible YES case
//1. The two strings are the same
//2. There are exactly two positions where the strings are different, and you can make the strings become the same by swapping these two positions
int main(){
	string s,t;
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		cin>>s>>t;
		int ps=-1,pt=-1;  
		//we are going to swap s[ps] with t[pt]
		bool diff3=false; //flag for too many different characters
		for(int i=0;i<n;i++){
			if(s[i]!=t[i]){
				if(ps<0) ps=i;
				else if(pt<0) pt=i;
				else diff3=true;
			}
		}
		if(diff3) puts("No"); //Three or more mismatch positions
		else if(ps<0&&pt<0) puts("Yes"); //Exactly match
		else if(pt<0) puts("No"); //Only one different position
		else if(s[ps]==s[pt]&&t[ps]==t[pt]) puts("Yes");
		else puts("No");
	}
	return 0;
}