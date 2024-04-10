#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;
char a[N],b[N];
vector<int> ans;

int main(){
	scanf("%d",&T);
	while(T--){
		ans.clear();
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		for(int i=1,r=1;i<=n;i=++r){
			while(r+1<=n&&a[r+1]==a[r])++r;
			ans.push_back(r);
		}
		bool w=(a[n]-'0')^1;
		for(int i=n;i>=1;--i)
		if(b[i]-'0'!=w){
			ans.push_back(i);
			w^=1;
		}
		printf("%d ",ans.size());
		for(int i=0;i<ans.size();++i){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}