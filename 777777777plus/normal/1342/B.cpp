#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
string s,t;

int main(){
	cin>>T;
	while(T--){
		cin>>t;
		int n=t.size();
		bool flag=1;
		for(int i=0;i<n-1;++i)
		if(t[i]!=t[i+1]){
			flag=0;
		}
		if(flag)cout<<t<<endl;
		else{
			s.clear();
			for(int i=0;i<n;++i){
				s+='1';
				s+='0';
			}
			cout<<s<<endl;
		}
	}
}