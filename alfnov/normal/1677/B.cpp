#include<bits/stdc++.h>
using namespace std;
int an[1000005];
int vist[1000005];
char a[1000005];
int s[1000005];
int main(){
	int T=1;
	cin>>T;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*m;++i)an[i]=0;
		for(int i=0;i<m;++i)vist[i]=0;
		scanf("%s",a+1);
		for(int i=1;i<=n*m;++i)s[i]=s[i-1]+(a[i]-'0');
		int gs=0;
		for(int i=1;i<=n*m;++i){
			if(a[i]=='1'){
				++vist[i%m];
				if(vist[i%m]==1)++gs;
			}
			an[i]+=gs;
		}
		for(int c=1;c<=m;++c){
			int he=0;
			for(int i=c;i<=n*m;i+=m){
				if(s[i]>s[max(0,i-m)])++he;
				an[i]+=he;
			}
		}
		for(int i=1;i<=n*m;++i)printf("%d ",an[i]);
		putchar('\n');
	}
	return 0;
}