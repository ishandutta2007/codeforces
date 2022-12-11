#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
int T,n,la,lb;
bool nd=0;
string s,ansa,ansb;
signed main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		nd=0;
		cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='2'){
				if(!nd){
					ansa+='1';
					ansb+='1';
				}else{
					ansa+='0';
					ansb+='2';
				}
			}else if(s[i]=='0'){
				ansa+='0';
				ansb+='0';
			}else{
				if(!nd){
					ansa+='1';
					ansb+='0';
					nd=1;
				}else{
					ansa+='0';
					ansb+='1';
				}
			}
		}
		cout<<ansa<<endl<<ansb<<endl;
		ansa.clear();
		ansb.clear();
	}
	return 0;
}