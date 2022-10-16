#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll q,a,b,c;
int main()
{
	q=read();
	for(int i=0;i<q;i++){
		a=read(),b=read(),c=read();
		cout<<(a+b+c)/2<<endl;
	}
	return 0;
}