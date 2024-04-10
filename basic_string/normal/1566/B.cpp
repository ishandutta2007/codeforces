#include<bits/stdc++.h>
using namespace std;
char s[100009];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	cin>>T;
	while(T--){
		cin>>(s+1),n=strlen(s+1);
		for(i=1;i<=n;++i)if(s[i]=='0')goto g1;
		cout<<0<<'\n';continue;
		g1:;
		for(i=1;i<=n;++i){
			if(s[i]=='0'){j=i;break;}
		}
		for(i=n;i;--i)if(s[i]=='0'){k=i;break;}
		for(i=j;i<=k;++i)if(s[i]=='1'){goto g2;}
		cout<<1<<'\n';continue;
		g2:;
		cout<<2<<'\n';
	}
	return 0;
}