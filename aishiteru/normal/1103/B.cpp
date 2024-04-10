#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int lim=1e9,lim2=2e9;
string S,s;
template <class I>
il I Min(I p,I q){return p<q?p:q;}
il void que(ct x,ct y){cout<<'?'<<' '<<x<<' '<<y<<endl,cout<<flush,cin>>s;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cin>>S;
	while(S!="end"){
		it l=1,r=1e9,i,mid,ans;
		for(i=1;i<=lim;i<<=1){
			que(i>>1,i);
			if(s=="x"){l=i>>1,r=i;break;}
		}
		ans=r;
		while(l+1<r) mid=l+r>>1,que(l,mid),s=="x"?ans=r=mid:l=mid;
		cout<<'!'<<' '<<r<<endl,cout<<flush,cin>>S;
	}
	return 0;
}