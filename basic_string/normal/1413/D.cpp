#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
vector<pair<int,int> >v;
int st[N],tp,ans[N];
int main(){
	int n,i,j,k,ct=0;
	char c;
	scanf("%d",&n);
	for(i=2*n;i;--i){
		scanf(" %c",&c);
		if(c=='+')v.push_back({1,0}),st[++tp]=++ct;
		else{
			scanf("%d",&j),ans[st[tp--]]=j;
			if(v.empty()||v.back().second>j)return puts("NO"),0;
			--v.back().first,k=0;
			while(!v.empty()&&v.back().second<j)k+=v.back().first,v.pop_back();
			if(k>0)v.push_back({k,j});
		}
	}
	puts("YES");
	for(i=1;i<=n;++i)printf("%d ",ans[i]); 
	return 0;
}