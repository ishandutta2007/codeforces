#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>E[100001];
bool v[100001],chk,p[100001];
int n,m,A,B,i,j,k,X,Y,r[100001],c;
int main()
{
	int a,b;
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for(i=1;i<=n;i++){
		if(E[i].size()<=A)continue;
		for(j=0;j<E[i].size();j++)v[E[i][j]]=1;
		for(j=0;j<E[i].size();j++){
			a=E[i][j];
			if(E[a].size()<=B)continue;
			X=E[i].size()-1-A;
			Y=0;
			c=0;
			for(k=0;k<E[a].size()&&Y<B;k++){
				if(E[a][k]==i)continue;
				if(X&&v[E[a][k]])X--,Y++,p[E[a][k]]=1,r[c++]=E[a][k];
				else if(!v[E[a][k]])Y++,r[c++]=E[a][k];
			}
			if(Y==B){
				chk=1;
				printf("YES\n%d %d\n",i,a);
				X=0;
				for(k=0;k<E[i].size();k++){
					if(!p[E[i][k]]&&E[i][k]!=a){
						printf("%d ",E[i][k]);
						X++;}
					if(X==A)break;
				}
				printf("\n");
				for(k=0;k<c;k++)printf("%d ",r[k]);
				printf("\n");
				break;
			}
			for(k=0;k<c;k++)p[r[k]]=0;
		}
		if(chk)break;
		for(j=0;j<E[i].size();j++)v[E[i][j]]=0;
	}
	if(!chk)printf("NO\n");
}