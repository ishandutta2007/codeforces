#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 222222;
const int M = 5e6+N;
int n,m=5e6,s[M],t[N],a[M],b[M];
vector<int> v[M],p;
int main(){
	int i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		s[x]++;
		v[x].push_back(i);
	}
	for(i=1;i<=m;i++){
		if(s[i]>=4){
			printf("YES\n%d %d %d %d\n",v[i][0],v[i][1],v[i][2],v[i][3]);
			return 0;
		}
		if(s[i]>=2)
			p.push_back(i);
	}
	if(p.size()>=2){
		printf("YES\n%d %d %d %d\n",v[p[0]][0],v[p[1]][0],v[p[0]][1],v[p[1]][1]);
		return 0;
	}
	if(p.size()==1){
		for(i=1;i<p[0];i++){
			if(s[i]&&s[p[0]*2-i]){
				printf("YES\n%d %d %d %d\n",v[p[0]][0],v[p[0]][1],v[i][0],v[p[0]*2-i][0]);
				return 0;
			}
		}
	}
	n=0;
	for(i=1;i<=m;i++)
		if(s[i])
			t[++n]=i;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			x=t[i]+t[j];
			if(a[x]){
				printf("YES\n%d %d %d %d\n",v[t[i]][0],v[t[j]][0],v[a[x]][0],v[b[x]][0]);
				return 0;
			}
			a[x]=t[i],b[x]=t[j];
		}
	}
	printf("NO\n");
	return 0;
}