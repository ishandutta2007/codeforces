#include<bits/stdc++.h>
using namespace std;
set<int>st[27];
set<int>::iterator it;
char a[1000009],b[1000009];
int main(){
	int T,la,lb,i,ans,now;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",a,b),la=strlen(a),lb=strlen(b);
		for(i=0;i<26;++i)st[i].clear();
		for(i=0;i<la;++i)st[a[i]-'a'].insert(i);
		for(i=0;i<lb;++i){
			if(st[b[i]-'a'].empty()){
				puts("-1");
				goto ggg;
			}
		}
		ans=0,now=-1;
		for(i=0;i<lb;++i){
			it=st[b[i]-'a'].upper_bound(now);
			if(it==st[b[i]-'a'].end()){
				++ans,now=-1,it=st[b[i]-'a'].upper_bound(now);
			}
			now=*it;
		}
		printf("%d\n",ans+1);
		ggg:;
	}
	return 0;
}//stkjserkjs5jsr5js