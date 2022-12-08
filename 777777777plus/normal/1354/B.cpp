#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int last[3]={0,0,0};
		int ans=1e9;
		for(int i=1;i<=n;++i){
			last[s[i]-'1']=i;
			int p=*min_element(last,last+3);
			if(!p)continue;
			ans=min(ans,i-p+1);
		}
		if(ans==1e9)printf("0\n");
		else printf("%d\n",ans);
	}
}