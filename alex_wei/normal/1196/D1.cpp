#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll q,n,k,ch[200002];
char d[3]={'R','G','B'};
string s;
int main()
{
	q=read();
	for(int a=0;a<q;a++){
		n=read(),k=read();
		cin>>s;
		ll ans=200002;
		for(int i=1;i<=s.size();i++){
			ch[i]=ch[i-1]+(s[i-1]!=d[(i-1)%3]);
			if(i>=k)
				ans=min(ans,ch[i]-ch[i-k]);
		}
		for(int i=1;i<=s.size();i++){
			ch[i]=ch[i-1]+(s[i-1]!=d[i%3]);
			if(i>=k)
				ans=min(ans,ch[i]-ch[i-k]);
		}
		for(int i=1;i<=s.size();i++){
			ch[i]=ch[i-1]+(s[i-1]!=d[(i+1)%3]);
			if(i>=k)
				ans=min(ans,ch[i]-ch[i-k]);
		}
		cout<<ans<<endl;
	}
	return 0;
}