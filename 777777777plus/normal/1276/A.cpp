#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n;
char s[N];
vector<int>ans;

int main(){
	scanf("%d",&T);
	while(T--){
		ans.clear();
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;++i){
			if(i+4<=n&&s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e'){
				s[i+2]='a';
				ans.push_back(i+2);
			}
			else if(i>=3&&s[i-2]=='o'&&s[i-1]=='n'&&s[i]=='e'){
				s[i-1]='a';
				ans.push_back(i-1);
			}
			else if(i>=3&&s[i-2]=='t'&&s[i-1]=='w'&&s[i]=='o'){
				s[i-1]='a';
				ans.push_back(i-1);
			}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
		printf("\n");
	}
}