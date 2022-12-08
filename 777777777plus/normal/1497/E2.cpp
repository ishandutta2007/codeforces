#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const int M = 1e7+1;

int Case;
int n,k,a[N];
int q[M];
bool vis[M];
map<int,int> last;
set<int> s;
set<int> ::iterator it;
int l[N][22],f[N][22];

int main(){
	for(int i=2;i*i<M;++i)
	if(!vis[i]){
		q[++q[0]]=i;
		for(int j=2;i*j<M;++j){
			vis[i*j]=1;
		}
	}
	scanf("%d",&Case);
	while(Case--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			for(int j=1;j<=q[0];++j)
			while(a[i]%(q[j]*q[j])==0)a[i]/=q[j]*q[j];
		}
		s.clear();
		last.clear();
		for(int i=1;i<=n;++i){
			if(last[a[i]]){
				s.insert(last[a[i]]);
			}
			last[a[i]]=i;
			it=s.end();
			memset(l[i],0,sizeof(l[i]));
			for(int j=1;j<=k+1;++j){
				if(it==s.begin())break;
				--it;
				l[i][j]=*it;
			}
		}
		for(int j=1;j<=k;++j)f[0][j]=2e9;
		f[0][0]=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=k;++j){
				f[i][j]=2e9;
				for(int t=0;t<=j;++t){
					f[i][j]=min(f[i][j],f[l[i][t+1]][j-t]+1);
				}
			}
		}
		cout<<*min_element(f[n],f[n]+k+1)<<endl;
	}
}