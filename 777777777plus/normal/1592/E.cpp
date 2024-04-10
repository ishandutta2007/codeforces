#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n;
int a[N];
int ans,c[N];
int s[N],vis[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int totw=0;
	for(int i=19;~i;--i){
		for(int j=1;j<=n;++j){
			c[j]=a[j]>>i;
			c[j]^=c[j-1];
		}
		++totw;
		vis[0]=totw;
		s[0]=0;
		for(int j=1;j<=n;++j)
		if(!(a[j]>>i&1)){
			++totw;
			vis[c[j]]=totw;
			s[c[j]]=j;
		}
		else{
			if(vis[c[j]]!=totw){
				vis[c[j]]=totw;
				s[c[j]]=j;
			}
			else{
				ans=max(ans,j-s[c[j]]);
			}
		}
	}
	printf("%d\n",ans);
}