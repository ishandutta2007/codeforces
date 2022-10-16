#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
void run(){
	int b=read(),w=read();
	int sx=200001,sy=200000;
	if(b>w)swap(b,w),sy++;
	int n=w-b;
	int maxv=3*b+1;
	if(w>maxv)cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i=0;i<b;i++) 
			cout<<sx<<" "<<sy+i*2<<"\n"<<sx<<" "<<sy+i*2+1<<"\n";
		if(n&1)
			cout<<sx<<" "<<sy-1<<"\n",n--;
		for(int i=0;i<n;i+=2) 
			cout<<sx-1<<" "<<sy+i<<"\n"<<sx+1<<" "<<sy+i<<"\n";
	}
}

int q=read(); 
int main(){
	for(int i=1;i<=q;i++)
		run();
	return 0;
}