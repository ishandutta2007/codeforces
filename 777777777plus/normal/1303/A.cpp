#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
string s;

int main(){
	cin>>T;
	while(T--){
		cin>>s;
		int n=s.size(),l=-1,r=-2;
		for(int i=0;i<n;++i)
		if(s[i]=='1'){
			if(l==-1)l=i;
			r=i;
		}
		int ans=0;
		for(int i=l;i<=r;++i)if(s[i]=='0')ans++;
		cout<<ans<<endl;
	}
}