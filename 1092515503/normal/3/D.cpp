#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<pair<int,int> >q;
int n,a[100100],b[100100],res,cnt;
char s[100100];
signed main(){
	scanf("%s",s),n=strlen(s);
	for(int i=0;i<n;i++)if(s[i]=='?')scanf("%lld%lld",&a[i],&b[i]),res+=b[i];
	for(int i=0;i<n;i++){
		if(s[i]=='(')cnt++;
		else cnt--;
		if(s[i]=='?')q.push(make_pair(b[i]-a[i],i)),s[i]=')';
		if(cnt<0){
			if(q.empty()){res=-1;break;}
			cnt+=2,res+=-q.top().first,s[q.top().second]='(',q.pop();
		}
	}
	if(cnt!=0)res=-1;
	printf("%lld\n",res);
	if(res!=-1)printf("%s",s);
	return 0;
}