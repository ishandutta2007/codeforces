#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int m,n,x,E[100001][2],deg[5],s,w[10],C,tp[10];
bool v[5][5],vv[10],chk;
set<int>Set;
set<int>::iterator it;
void DFS(int x,int a){
	vv[x]=true;
	tp[a]=x;
	int i;
	if(a==m){
		for(i=0;i<m;i++)printf("%d %d\n",w[tp[i]],w[tp[i+1]]);
		chk=true;
		return;
	}
	for(i=0;i<C;i++){
		if(!vv[i]&&E[w[x]][0]!=w[i] && E[w[x]][1]!=w[i]){
			DFS(i,a+1);
			if(chk)return;
		}
	}
	if(a==m-1 && a!=0){
		if(E[w[x]][0]!=w[0] && E[w[x]][1]!=w[0]){
			DFS(0,a+1);
			return;
		}
	}
	vv[x]=false;
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	int a,b,c,d,j;
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(n<=4)v[a][b]=v[b][a]=true;
		if(E[a][0])E[a][1]=b;
		else E[a][0]=b;
		if(E[b][0])E[b][1]=a;
		else E[b][0]=a;
	}
	if(n<=4){
		if(n==2 || (n==3 && m>=2) || (n==4 && m>=4))printf("-1\n");
		else if(n==4 && m==3 && (!E[1][0] || !E[2][0] || !E[3][0] || !E[4][0]))printf("-1\n");
		else{
			for(i=1;i<=n;i++){
				for(j=i+1;j<=n;j++){
					if(m && !v[i][j] && deg[i]<2 && deg[j]<2){
						deg[i]++,deg[j]++;
						printf("%d %d\n",i,j);
						m--;
					}
				}
			}
		}
		return 0;
	}
	x=1,s=1;
	for(i=1;i<=n;i++)Set.insert(i);
	while(1){
		if(m<=9){
			break;
		}
		it=Set.begin();
		s=x=*it;
		Set.erase(it);
		a=0;
		while(1){
			a++;
			if(x!=s && E[x][0]!=s && E[x][1]!=s && a!=2){
				m--;
				printf("%d %d\n",x,s);
				break;
			}
			for(it=Set.begin();it!=Set.end();it++){
				if(*it!=E[x][0] && *it!=E[x][1])break;
			}
			printf("%d %d\n",x,*it);
			x=*it;
			Set.erase(it);
			m--;
		}
	}
	for(it=Set.begin();it!=Set.end();it++){
		w[C++]=*it;
	}
	DFS(0,0);
	return 0;
}