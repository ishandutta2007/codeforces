#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int n;
char s[N],s1[N];
int k;
 
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int totmx=0;
	for(int i=1;i<=n;++i){
		s1[i]=s[i];
		if(s[i]=='L'){
			static int c;
			totmx+=i-(++c);
		}
	}
	int totmn=0;
	for(int t=1;;++t){
		vector<int>ans;
		for(int i=n-1;i>=1;--i)
		if(s1[i]=='R'&&s1[i+1]=='L'){
			ans.push_back(i);
		}
		if(!ans.size()){
			totmn=t-1;
			break;
		}
		for(int i=0;i<ans.size();++i){
			swap(s1[ans[i]],s1[ans[i]+1]);
		}
	}
	if(k>totmx||k<totmn){
		puts("-1");
		return 0;
	}
	set<int>p;
	for(int i=1;i<n;++i)
	if(s[i]=='R'&&s[i+1]=='L'){
		p.insert(i);
	} 
	for(int t=1;t<=k;++t){
		vector<int>ans;
		for(auto i:p)
		if(totmx>k-t){
			totmx--;
			ans.push_back(i);
		}
		else break;
		printf("%d ",ans.size());
		for(int i=0;i<ans.size();++i){
			printf("%d ",ans[i]);
			swap(s[ans[i]],s[ans[i]+1]);
			p.erase(ans[i]);
		}
		for(int i=0;i<ans.size();++i){
			if(ans[i]+2<=n&&s[ans[i]+2]=='L'){
				p.insert(ans[i]+1);
			}
			if(ans[i]-1>=1&&s[ans[i]-1]=='R'){
				p.insert(ans[i]-1);
			}
		}
		printf("\n");
	}
}