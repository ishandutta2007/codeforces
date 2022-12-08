#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;

int T;
int n,b[N],m;
bool a[N];
ll ans;

void dfs(int x){
	if(x>m-2){
		ll res=1;
		for(int i=1;i<=m;++i){
			int w=b[i]-(i>=3?(int)a[i-2]:0);
			if(a[i])w+=10;
			if(w<0)return;
			ll t=0;
			for(int j=0;j<=w;++j)
			if(j<10&&w-j<10)++t;
			res*=t;
		}
		ans+=res;
		return;	
	}
	for(int i=0;i<2;++i){
		a[x]=i;
		dfs(x+1); 
	}
}

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		m=ans=0;
		memset(a,0,sizeof(a));
		while(n)b[++m]=n%10,n/=10;
		dfs(1);
		cout<<ans-2<<endl;
	}
}