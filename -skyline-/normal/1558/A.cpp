#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,a,b,f,s,n;
int q[200005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		n=a+b;
		f=n/2,s=n-f;
		if(a>b) swap(a,b);
		for(int i=0;i<=n;++i)q[i]=0;
		int cnt=0;
		for(int k=0;k<=s;++k){
			int x=n-b-s+k;
			if(x>=0&&x<=a){
				x+=k;
				if(!q[x])q[x]=1,++cnt;
				x=n-x;
				if(!q[x])q[x]=1,++cnt;
				
			}
		}
		printf("%d\n",cnt);
		for(int i=0;i<=n;++i){
			if(q[i]){
				--cnt;
				if(cnt)printf("%d ",i);
				else printf("%d\n",i);
			}
		}
	}
    return 0;
}