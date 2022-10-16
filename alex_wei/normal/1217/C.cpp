#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
string s;
int main()
{
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>s;
		ll ans=0;
		for(int i=0;i<s.size();i++){
			int pos=i,num=s[i]-'0';
			if(num==1)ans++;
			while(pos<s.size()-1&&num<=pos-i+1){
				pos++;
				num=(num<<1)+s[pos]-'0';
				if(num>=1&&num<=pos-i+1)ans++;
			}
			while(i<s.size()&&s[i]=='0')i++;
		}
		cout<<ans<<endl;
	}
    return 0;
}