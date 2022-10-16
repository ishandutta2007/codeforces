#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,n;
string s,t;
bool tp(char z){return z!='1'&&z!='2';} 
int main()
{
	cin>>q;
	while(q--){
		cin>>n>>s>>t;
		int odd=0,pd=1;
		for(int i=0;i<n;i++){
			if(tp(s[i])!=tp(t[i])){
				if(odd%2&&!tp(s[i]))pd=0;
				if(odd%2==0&&!tp(t[i]))pd=0;
			}
			else odd+=tp(odd%2?t[i]:s[i]);
		}
		if(pd&&odd%2)cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}