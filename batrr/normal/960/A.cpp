#include <bits/stdc++.h>
 
#define nm "" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                                                                                                            
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e6+123,mod=1e9+7,N=2e6+123;
string s;
int i,cnta,cntb,cntc;
int main(){
	cin>>s;
	while(i<s.size()){
		if(s[i]=='a')
			cnta++;
		else
			break;
		i++;
	}
	while(i<s.size()){
		if(s[i]=='b')
			cntb++;
		else
			break;
		i++;
	}
	while(i<s.size()){
		if(s[i]=='c')
			cntc++;
		else
			break;
		i++;
	}
	if(i==s.size() && ( cntc==cnta || cntc==cntb ) && cnta>0 && cntb>0)
		cout<<"YES";
	else
		cout<<"NO";
}