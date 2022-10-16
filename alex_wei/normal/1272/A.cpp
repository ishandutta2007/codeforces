#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x=0,sign=1;char s=getchar();
	while(!isdigit(s)){
		if(s=='-')sign=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*sign;
}
int t,a[4],ans;
int main(){
	cin>>t;
	while(t--){
		ans=2e9+2;
		cin>>a[1]>>a[2]>>a[3];
		for(int i=-1;i<2;i++)
			for(int j=-1;j<2;j++)
				for(int k=-1;k<2;k++){
					int p=a[1]+i,q=a[2]+j,r=a[3]+k;
					ans=min(ans,abs(p-q)+abs(p-r)+abs(q-r));
				}
		cout<<ans<<endl;
	}
    return 0;
}