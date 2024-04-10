#include<bits/stdc++.h>
using namespace std;
const int N = 1111111;
int n,m,q,b[N],c[N];
vector<int> v[N];
char s[N];
int main(){
	int T,i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",s+1);
		v[i].push_back(0);
		for(j=1;j<=m;j++)
			v[i].push_back(s[j]=='X');
	}
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
			if(v[i][j+1]&&v[i+1][j])
				b[j]++;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(v[i][j]&&!c[j])
				c[j]=i;
	for(i=1;i<=m;i++)
		b[i]+=b[i-1];
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(b[y-1]==b[x-1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}