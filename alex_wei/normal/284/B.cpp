#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,p,a;
string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++)p+=s[i]=='I',a+=s[i]=='A';
	if(p>=2)puts("0");
	else if(p==1)puts("1"); 
	else cout<<a<<endl;
	return 0;
}