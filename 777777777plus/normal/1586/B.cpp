#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T;
int n,m;
int a[N],b[N],c[N],v[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)v[i]=0;
		for(int i=1;i<=m;++i)scanf("%d%d%d",&a[i],&b[i],&c[i]),v[b[i]]=1;
		for(int i=1;i<=n;++i)
		if(!v[i]){
			for(int j=1;j<=n;++j)
			if(i!=j){
				printf("%d %d\n",i,j);
			}
			break;
		}
	}
}