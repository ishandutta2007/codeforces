#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll q,n,k,a[200002],cnt,b[200002]; 
int main()
{
	q=read();
	for(int p=0;p<q;p++){
		n=read(),k=read();
		cnt=0;
		for(int i=0;i<n;i++){
			a[i]=read();
			if(a[i]%2)b[++cnt]=i+1;
		}
		if(cnt<k||abs(cnt-k)%2)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int i=1;i<k;i++)
				cout<<b[i]<<" ";
			cout<<n<<endl;
		}
	}
	return 0;
}