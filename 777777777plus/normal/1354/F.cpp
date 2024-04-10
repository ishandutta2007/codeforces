#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 77;

int T;
int n,k;
int a[N],b[N],id[N];
ll f[N][N];
int pre[N][N];

bool cmp(int x,int y){
	return b[x]<b[y];
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
		for(int i=1;i<=n;++i)id[i]=i; 
		sort(id+1,id+n+1,cmp);
		for(int i=0;i<=n;++i)
		for(int j=0;j<=i;++j){
			f[i][j]=-1e18;
			pre[i][j]=0;
		}
		f[0][0]=0;
		for(int i=0;i<n;++i)
		for(int j=0;j<=i;++j)
		if(f[i][j]>=0){
			ll w=f[i][j]+j*b[id[i+1]]+a[id[i+1]];
			if(w>f[i+1][j+1]){
				f[i+1][j+1]=w;
				pre[i+1][j+1]=id[i+1];
			}
			w=f[i][j]+(k-1)*b[id[i+1]];
			if(w>f[i+1][j]){
				f[i+1][j]=w;
				pre[i+1][j]=-id[i+1];
			}
		}
		vector<int> A,B,ans;
		for(int i=n;i>=1;--i){
			int t=pre[i][k];
			if(t>0){
				--k;
				A.push_back(t);
			}
			else{
				B.push_back(-t);
			}	
		}
		reverse(A.begin(),A.end());
		reverse(B.begin(),B.end());
		for(int i=0;i<A.size()-1;++i){
			ans.push_back(A[i]);
		}
		for(int i=0;i<B.size();++i){
			ans.push_back(B[i]);
			ans.push_back(-B[i]);
		}
		ans.push_back(A[A.size()-1]);
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
		printf("\n");
	}
}