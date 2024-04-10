#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,k1,k2,a[105],b[105];
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
int main(){
	cin>>t;
	while(t--){
		n=read();
	    k1=read();
	    k2=read();
	    for(int i=1;i<=k1;i++)a[i]=read();
	    for(int i=1;i<=k2;i++)b[i]=read();
	    int mx1=0,mx2=0;
	    for(int i=1;i<=k1;i++)mx1=max(mx1,a[i]);
	    for(int i=1;i<=k2;i++)mx2=max(mx2,b[i]);
	    if(mx1>mx2)puts("YES");
	    else puts("NO");
	}
    return 0;
}