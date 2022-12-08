#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
ll n;
ll l,r,w[N],ans[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&l,&r);
		for(int i=1;i<n;++i)w[i]=(n-i)*2;
		for(int i=1;i<n;++i)w[i]+=w[i-1];
		int flag;
		for(int i=1;i<n;++i){
			if(w[i]>=l){
				int c=l-w[i-1];
				if(c&1)flag=0;
				else flag=1;
				ans[0]=i;
				ans[1]=(c+1)/2+i;
				break;
			}
		}
		vector<ll> p;
		bool flag1=0;
		if(r==n*(n-1)+1)flag1=1;
		r=r-l+1;
		while(p.size()<r+flag){
			p.push_back(ans[0]);
			p.push_back(ans[1]);
			if(ans[1]<n)++ans[1];
			else{
				++ans[0];
				ans[1]=ans[0]+1;
			}
		}
		for(int i=flag;i<flag+r;++i){
			if(i==flag+r-1&&flag1)printf("1 ");
			else printf("%lld ",p[i]);
		}
		printf("\n");
	}
}