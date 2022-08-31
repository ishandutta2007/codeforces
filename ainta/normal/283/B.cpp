#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>E[400001];
int n,w[200001],i,j,a,Q[400001],h,t,x,o;
__int64 D[400001];
bool v[400001];
int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		scanf("%d",&w[i]);
		if(0<i+w[i] && i+w[i]<=n){
			E[i+w[i]+n].push_back(i);
		}
		if(0<i-w[i] && i-w[i]<=n){
			E[i-w[i]].push_back(i+n);
		}
	}
	for(i=2;i<=n;i++){
		if(i<=w[i])D[i+n]=w[i],v[n+i]=true,Q[++t]=n+i;
		if(i+w[i]>n)D[i]=w[i],v[i]=true,Q[++t]=i;
	}
	while(h<t){
		x=Q[++h];
		for(i=0;i<E[x].size();i++){
			o=E[x][i];
			if(!v[o]){
				if(o<=n)D[o]=D[x]+w[o];
				else D[o]=D[x]+w[o-n];
				v[o]=true;
				Q[++t]=o;
			}
		}
	}
	for(i=1;i<n;i++){
		if(!v[n+i+1])printf("-1\n");
		else printf("%I64d\n",(__int64)i+D[n+i+1]);
	}
}