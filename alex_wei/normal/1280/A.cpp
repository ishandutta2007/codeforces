#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int t,x,Z;
ll q[1000005];
string s;
int main(){
	cin>>t;
	while(t--){
		cin>>x>>s;
		Z=0;
		q[0]=s.size();
		for(int pos=1;pos<=x;pos++){
			q[pos]=(q[pos-1]+1ll*(ll)(s[pos-1]-'1')*(q[pos-1]-pos+mod))%mod;
			if(!Z){
				int tmp=s.size();
				for(int i=1;i<=s[pos-1]-'1';i++){
					if(s.size()>=x)break;
					for(int j=pos;j<tmp;j++){
						s+=s[j];
						if(s.size()>=x)break;
					}
				}
			}
			if(q[pos]>=x&&!Z)Z=1;
		}
		cout<<q[x]<<endl;
	}
    return 0;
}
/*
1
333333
333333
*/