//
#include<bits/stdc++.h>
using namespace std;
unordered_multiset<string>st;
string s[1509],g;
int main(){
	register int n,k,i,j,p;
	register long long ans=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)cin>>s[i],st.insert(s[i]);
	g=s[1];
	for(i=1;i<=n;++i){
		st.erase(st.find(s[i]));
		for(j=1;j<i;++j){
			for(p=0;p<k;++p){
				if(s[i][p]==s[j][p])g[p]=s[i][p];
				else if(s[i][p]!='S'&&s[j][p]!='S')g[p]='S';
				else if(s[i][p]!='E'&&s[j][p]!='E')g[p]='E';
				else if(s[i][p]!='T'&&s[j][p]!='T')g[p]='T';
			}
			ans+=st.count(g);
		}
	}
	printf("%lld",ans);
	return 0;
}