#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 998244353;

int n,m;
int a[N],b[N];
map<int,int> p;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	ll ans=1;
	for(int i=1;i<=n;++i)p[a[i]]=i;
	for(int r=n+1,l=n+1;m;r=l,--m){
		while(l>1&&a[l-1]>=b[m])l--;
		if(p.find(b[m])==p.end()||l>p[b[m]]){
			printf("0\n");
			return 0;
		}
		if(m==1){
			if(l==1);
			else{
				printf("0\n");
				return 0;
			}
		}
		else (ans*=p[b[m]]-l+1)%=mod;
	}
	printf("%d\n",int(ans));
}