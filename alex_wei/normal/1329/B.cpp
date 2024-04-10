#include<bits/stdc++.h>
using namespace std;
int t,d,m,ans,c;
int main(){
	for(cin>>t;t;t--){
	    cin>>d>>m,ans=1,c=log2(d);
	    for(int i=0;i<=c;i++)ans=1ll*ans*(i<c?(1<<i)+1:d-(1<<i)+2)%m;
	    cout<<(ans-1+m)%m<<endl;
	}
}