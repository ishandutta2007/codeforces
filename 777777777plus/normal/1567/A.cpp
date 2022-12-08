#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n;
string s;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		for(int i=0;i<n;++i)
		if(s[i]=='U')s[i]='D';
		else if(s[i]=='D')s[i]='U';
		cout<<s<<endl;
	}
}