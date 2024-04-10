#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 222222;
int n,m,s[N],a[N];
vector<int> v[N];
int main(){
	int T,i,j,o,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++){
			scanf("%d",&o);
			for(j=0;j<o;j++){
				scanf("%d",&x);
				v[i].push_back(x);
			}
			if(o==1)
				s[x]++,a[i]=x;
		}
		for(i=1;i<=m;i++){
			o=v[i].size();
			if(o==1)
				continue;
			x=0;
			for(j=0;j<o;j++)
				if(!x||s[x]>s[v[i][j]])
					x=v[i][j];
			s[x]++,a[i]=x;
		}
		o=1;
		for(i=1;i<=n;i++)
			if(s[i]>(m+1)/2)
				o=0;
		if(o){
			printf("YES\n");
			for(i=1;i<=m;i++)
				printf("%d ",a[i]);
			printf("\n");
		}
		else
			printf("NO\n");
		for(i=1;i<=n;i++)
			s[i]=0;
		for(i=1;i<=m;i++)
			v[i].clear();
	}
	return 0;
}