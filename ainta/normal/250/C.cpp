#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,k,i,w[100001],j,Z[100001],t,BC,AC,M,x;
vector <int> P[100001];
int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		P[w[i]].push_back(i);
	}
	for(i=1;i<=k;i++){
		BC=AC=0;
		for(j=0;j<P[i].size();j++){
			t=P[i][j];
			if(t!=1&&w[t]!=w[t-1]){
				BC=w[t-1];AC=0;
				Z[i]++;
			}
			if(t!=n&&w[t]!=w[t+1]){
				Z[i]++;
				AC=w[t+1];
			}
			if(BC&&AC&&BC!=AC){
				Z[i]--;
				BC=AC,AC=0;
			}
		}
	}
	x=M=-1;
	for(i=1;i<=n;i++){
		if(Z[i]>M)M=Z[i],x=i;
	}
	printf("%d\n",x);
}