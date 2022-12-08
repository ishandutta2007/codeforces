#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll mod = 1e9+7;

int n,Q;
int a[N];
map<pair<int,int>,int> cnt;
int s[N];
ll ans=1;

void mul(int p,int x){
	for(int i=2;i*i<=x;++i)
	while(x%i==0){
		x/=i;
		if((++cnt[make_pair(p,i)])==1){
			s[i]++;
			if(s[i]==n){
				ans=ans*i%mod;
				for(int j=1;j<=n;++j){
					if(!--cnt[make_pair(j,i)])--s[i];
				}
			}
		}
	}
	if(x>1){
		int i=x;
		if((++cnt[make_pair(p,i)])==1){
			s[i]++;
			if(s[i]==n){
				ans=ans*i%mod;
				for(int j=1;j<=n;++j){
					if(!--cnt[make_pair(j,i)])--s[i];
				}
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		mul(i,a[i]);
	}
	for(int i=1,p,x;i<=Q;++i){
		scanf("%d%d",&p,&x);
		mul(p,x);
		printf("%lld\n",ans);
	}
	
}