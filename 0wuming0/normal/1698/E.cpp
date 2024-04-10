#include<bits/stdc++.h>
using namespace std;
 
const long long M=998244353;
const int N=2e5+10;
 
int a[N], b[N], pos[N], vis[N];
int n, s;
 
int main(){
	int t; cin>>t;
	while(t--){
		scanf("%d%d", &n, &s);
		for(int i=1; i<=n; ++i) vis[i]=1;
		for(int i=1; i<=n; ++i){
			scanf("%d", a+i);
			pos[a[i]]=i;
		}
		for(int i=1; i<=n; ++i){
			scanf("%d", b+i);
			if(b[i]!=-1) vis[b[i]]=0;
		}
		for(int i=n-1; i>=1; --i){
			vis[i]+=vis[i+1];
		}
		long long ans=1;
		int num=0;
		for(int i=n; i>=1; --i){
			if(b[pos[i]]==-1){
				if(i-s>0) ans=ans*(vis[i-s]-num)%M;
				else ans=ans*(vis[1]-num)%M;
				num++;
			}else{
				ans=ans*(b[pos[i]]>=i-s);
//				printf("b=%d i-s=%d\n", b[pos[i]], i-s);
			}
//			printf("i=%d ans=%d\n", i, ans);
		}
		printf("%lld\n", ans);
	}
}