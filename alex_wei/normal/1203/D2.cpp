#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
string s,t;
int posf[200005],posl[200005],posa,posb,ans;
int main()
{
	cin>>s>>t;
	while(posa<s.size()&&posb<t.size()){
		if(s[posa]==t[posb])posf[posb]=posa,posb++;
		posa++;
	}
	posa=s.size()-1,posb=t.size()-1;
	while(posa>=0&&posb>=0){
		if(s[posa]==t[posb])posl[posb]=posa,posb--;
		posa--;
	}
	ans=max((int)s.size()-1-posf[t.size()-1],posl[0]);
	for(int i=1;i<t.size();i++)
		ans=max(ans,posl[i]-posf[i-1]-1);
	cout<<ans;
	return 0;
}