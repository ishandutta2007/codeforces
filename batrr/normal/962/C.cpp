#include <bits/stdc++.h>
 
#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                                                                                                            
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=3e5+123,N=2e6+123,mod=1e9+7,block=600;
ll n,ans=1e9;
string s;
int main(){                 
	cin>>s;
	n=s.size();      
	for(int i=0;i<(1<<n);i++){
		ll x=0,cnt=0;
		for(int j=0;j<n;j++){
			if( ( (1<<j) & i) ){
				if(x==0 && s[j]=='0')
					cnt=1e9;
				x=x*10+s[j]-'0';	
			}else{
				cnt++;
			}
		}
		if(x!=0 && (int)sqrt(x)*(int)sqrt(x)==x)
			ans=min(ans,cnt);		
	}
	if(ans==1e9)	
		ans=-1;
	cout<<ans;
}