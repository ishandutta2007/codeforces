#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;
int a[N],p[N],ans[N];
bool vis[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),p[a[i]]=i,vis[i]=0;
		int m=0;
		for(int i=n;i>=1;--i)
		if(!vis[p[i]]){
			int pos=p[i];
			while(pos<=n&&!vis[pos]){
				ans[++m]=a[pos];
				vis[pos]=1;
				pos++;
			}
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
	}
}