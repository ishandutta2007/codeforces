#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
	int n;
	long long a[26]={};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int m=strlen(s);
		vector<long long> v;
		for(int j=0;s[j];j++){
			if(j&&s[j]==s[j-1]) v.back()++;
			else v.push_back(1);
		}
		int fst=s[0]-'a',lst=s[m-1]-'a';
		if(v.size()==1){
			a[fst]*=(m+1);
			a[fst]+=m;
		}
		else if(fst==lst && a[fst]){
			a[fst]=v.front()+v.back()+1;
		}
		else{
			a[fst]=min(a[fst],1LL)+v.front();
			a[lst]=min(a[lst],1LL)+v.back();
		}
		for(int j=0;j<26;j++){
			if(j!=fst && j!=lst) a[j]=min(a[j],1LL);
		}
		int p=0;
		for(int j=0;j<v.size();j++){
			int cur=s[p]-'a';
			a[cur]=max(a[cur],v[j]);
			p+=v[j];
		}
		for(int j=0;j<26;j++) a[j]=min(a[j],1LL<<30);
	}
	long long ans=0;
	for(int i=0;i<26;i++) ans=max(ans,a[i]);
	printf("%lld\n",ans);
	return 0;
}