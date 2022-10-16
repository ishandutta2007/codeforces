#include<bits/stdc++.h>
using namespace std;
/////
#define int long long
int read(){
	int x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return x*sign;
}
int T,t,x,y,a[500005],FK[705][705],ans;
signed main() {
	T=read();
	for(int i=1;i<=T;i++){
		t=read(),x=read(),y=read();
		if(t==1){
        	a[x]+=y;
        	for(int j=1;j<=700;++j)
				FK[j][x%j]+=y;
    	}
    	else{
    	    ans=0;
    	    if(x>700)
				for(int j=y;j<=500000;j+=x)
					ans+=a[j];
    	    else ans=FK[x][y];
    	    cout<<ans<<endl;
    	}
    }
	return 0;
}