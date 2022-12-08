#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;


string s;

int main(){
	cin>>s;
	int n=s.size();
	bool flag=0;
	for(int i=0;i<n-1;++i)
	if(s[i]=='('&&s[i+1]==')'){
		flag=1;
	}
	if(!flag)puts("0");
	else{
		for(int i=1;i<n;++i){
			int c1=0,c2=0;
			for(int j=1;j<=i;++j)if(s[j-1]=='(')c1++;
			for(int j=i+1;j<=n;++j)if(s[j-1]==')')c2++;
			if(c1==c2){
				cout<<1<<endl;
				cout<<c1+c2<<endl;
				for(int j=1;j<=i;++j)if(s[j-1]=='(')cout<<j<<" ";
				for(int j=i+1;j<=n;++j)if(s[j-1]==')')cout<<j<<" ";
				return 0;
			}
		}
	}
}