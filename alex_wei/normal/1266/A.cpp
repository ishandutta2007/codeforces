#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
string s;
int main(){
	cin>>n;
	while(n--){
		cin>>s;
		int q=0,pd=0,p2=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'&&!pd)pd=1;
			else{
				if(s[i]%2==0)p2=1;
				q+=s[i]-48;
			}
		}
		if(pd&&p2&&q%3==0)cout<<"red\n";
		else cout<<"cyan\n";
	}
    return 0;
}