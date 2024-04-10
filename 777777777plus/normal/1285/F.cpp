#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;

int n;
int a[N],u[N],cnt[N];
vector<int>g[N],d[N];
ll ans;

void prepare(){
	static bool vis[N];
	static int p[N];
	u[1]=1;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			p[++p[0]]=i;
			u[i]=-1;
		}
		for(int j=1;j<=p[0]&&p[j]*i<N;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
			else u[i*p[j]]=-u[i];
		}
	}
	for(int i=1;i<N;++i)
	for(int j=1;i*j<N;++j)
	d[i*j].push_back(i);
}

void add(int x,int c){
	for(int i=0;i<d[x].size();++i){
		cnt[d[x][i]]+=c; 
	}
}

bool ask(int x){
	int ret=0;
	for(int i=0;i<d[x].size();++i){
		ret+=cnt[d[x][i]]*u[d[x][i]];
	}
	return ret>0;
}

int main(){
	prepare();
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i)
	if(a[i]==a[i+1]){
		ans=max(ans,(ll)a[i]);
	}
	//n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<d[a[i]].size();++j){
			int x=d[a[i]][j];
			g[x].push_back(a[i]/x);
		}
	}
	for(int i=1;i<N;++i){
		static int stack[N];
		static int top;
		while(top){
			add(stack[top--],-1);
		}
		for(int j=(int)g[i].size()-1;~j;--j){
			int x=g[i][j];
			while(top&&ask(x)){
				ans=max(ans,1ll*x*stack[top]*i);
				add(stack[top--],-1);
			}
			add(stack[++top]=x,1);
		}
	}
	cout<<ans<<endl;
}