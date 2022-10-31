#include<bits/stdc++.h>
const int Q=1000000007;
using namespace std;
char s[1001000];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		scanf("%s",s);
		bool in=true;
		long long ans=strlen(s);
		for(int i=0;i<x;i++){
			long long nxt=(i+1)+(ans-i-1+Q)%Q*(s[i]-'0');
			long long len=ans-i-1;
			if(in&&len>0){
				for(int j=0;j<len*(s[i]-'1')&&ans+j<x;j++){
					s[ans+j]=s[i+1+j%len];
				}
			}
			if(nxt>x) in=false;
			nxt%=Q;
			ans=nxt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}