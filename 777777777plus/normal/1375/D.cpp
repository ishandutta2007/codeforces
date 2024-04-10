#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int T;
int n,a[N];
bool use[N];

int mex(){
	static int totw,vis[N];
	++totw;
	for(int i=0;i<n;++i)vis[a[i]]=totw;
	int ret=0;
	while(vis[ret]==totw)++ret;
	return ret;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=0;i<=n;++i)use[i]=0;
		vector<int> ans;
		for(int i=0;i<n;++i){
			if(use[a[i]]){
				a[i]=mex();
				ans.push_back(i);
			}
			use[a[i]]=1;
		}
		while(1){
			int x=mex();
			if(x==n){
				bool flag=0;
				for(int j=0;j<n;++j)
				if(a[j]!=j){
					a[j]=x;
					ans.push_back(j);
					flag=1;
					break;
				}
				if(!flag)break;
			}
			else{
				a[x]=x;
				ans.push_back(x);
			}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]+1);
		printf("\n");
//		for(int i=0;i<n;++i)printf("%d ",a[i]);
//		printf("\n");
	}
}

/*
2 0 1 3 5 4 6 7 8
1
9
2 0 1 1 2 4 4 2 0
*/