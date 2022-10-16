#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
int q,n,a[402],len[10002];
int main()
{
	cin>>q;
	for(int B=0;B<q;B++){
		memset(len,0,sizeof(len));
		cin>>n;
		int tpd=1;
		for(int i=1;i<=4*n;i++)cin>>a[i],len[a[i]]++;
		for(int i=1;i<=1e4;i++)if(len[i]%2)tpd=0;
		if(!tpd){cout<<"NO\n";continue;}
		int l=1,r=1e4,area=-1;
		while(!len[l]&&l<=1e4)l++;
		while(!len[r]&&r>0)r--;
		while(l<=r){
			if(area==-1)area=l*r;
			if(l==r){if(len[l]%4||l*r!=area)tpd=0;break;}
			if(area!=l*r){tpd=0;break;}
			len[l]-=2,len[r]-=2;
			while(!len[l]&&l<=1e4)l++;
			while(!len[r]&&r>0)r--;
		}
		if(tpd)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
/*
10
4
1 2 3 6 1 2 3 6 1 2 3 6 1 2 3 6
*/