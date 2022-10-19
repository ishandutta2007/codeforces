#include<bits/stdc++.h>
using namespace std;
int n,m,col[210],loc[210],COL[210],LOC[210],s[210][210];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&s[i][j]);
	for(int i=0;i<n;i++){
		memset(col,-1,sizeof(col)),memset(loc,-1,sizeof(loc));
		loc[0]=0;
		bool ok=true;
		for(int j=0;j<i;j++)for(int k=0;k<m;k++){
			if(col[j]==-1)col[j]=loc[k]^s[j][k];
			if(loc[k]==-1)loc[k]=col[j]^s[j][k];
			if(col[j]^loc[k]^s[j][k])ok=false;
		}
		for(int j=i+1;j<n;j++)for(int k=0;k<m;k++){
			if(col[j]==-1)col[j]=loc[k]^!s[j][k];
			if(loc[k]==-1)loc[k]=col[j]^!s[j][k];
			if(col[j]^loc[k]^!s[j][k])ok=false;
		}
		if(!ok)continue;
		for(int j=0;j<=m;j++){
			memcpy(COL,col,sizeof(col)),memcpy(LOC,loc,sizeof(loc));
			ok=true;
			for(int k=0;k<m;k++){
				if(COL[i]==-1)COL[i]=LOC[k]^s[i][k]^(k>j);
				if(LOC[k]==-1)LOC[k]=COL[i]^s[i][k]^(k>j);
				if(COL[i]^LOC[k]^s[i][k]^(k>j))ok=false;
			}
			if(ok){
				puts("YES");
				for(int i=0;i<n;i++)printf("%d",COL[i]);puts("");
				for(int i=0;i<m;i++)printf("%d",LOC[i]);puts("");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}