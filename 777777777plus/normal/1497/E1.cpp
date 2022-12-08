#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const int M = 1e7+1;

int T;
int n,k,a[N];
int q[M];
bool vis[M];
map<int,int> last;

int main(){
	srand(time(NULL));
	for(int i=2;i*i<M;++i)
	if(!vis[i]){
		q[++q[0]]=i;
		for(int j=2;i*j<M;++j){
			vis[i*j]=1;
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			for(int j=1;j<=q[0];++j)
			while(a[i]%(q[j]*q[j])==0)a[i]/=q[j]*q[j];
		}
		int r=0,ans=0;
		for(int i=1;i<=n;++i)
		if(i==1||last[a[i]]){
			last.clear();
			++ans;
			last[a[i]]=1;
		}
		else{
			last[a[i]]=1;
		}
		printf("%d\n",ans);
	}
}