/*#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[3010];
int n,j,a,b,w[3010][2],Q[3010],D[3010],Res;
bool v[3010],P[3010][3010];
int Do(int A,int B){
	int i;
	int h,t,x,e=0,MM=n+1;
	h=t=0;
	Q[++t]=A;
	for(i=1;i<=n;i++)D[i]=0,v[i]=false;
	v[A]=1;
	while(t>h){
		x=Q[++h];
		for(i=0;i<E[x].size();i++){
			if(!v[E[x][i]]&&E[x][i]!=B){
				v[E[x][i]]=1;
				Q[++t]=E[x][i];
				D[t]=D[h];
				if(P[x][E[x][i]])e++,D[t]++;
				else D[t]--;
			}
		}
	}
	for(i=1;i<=t;i++){
		if(MM>t-1-e+D[i])MM=t-1-e+D[i];
	}
	return MM;
}
int main()
{
	int i;
	scanf("%d",&n);
	if(n==1){printf("%d\n",0);return 0;}
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		w[i][0]=a,w[i][1]=b;
		E[a].push_back(b);
		E[b].push_back(a);
		P[a][b]=true;
	}
	int tt;
	Res=n;
	for(i=1;i<n;i++){
		tt=Do(w[i][0],w[i][1])+Do(w[i][1],w[i][0]);
		if(Res>tt)Res=tt;
	}
	printf("%d\n",Res);
}*/
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[3010];
int n,j,a,b,w[3010][2],Q[3010],D[3010],D2[3010],p[3010],d[3010],Res,d2[3010];
bool v[3010],P[3010][3010];
int Do(int A,int B){
	int i;
	int h,t,x,e=0,MM=n+1;
	h=t=0;
	Q[++t]=A;
	for(i=1;i<=n;i++)D2[i]=d2[i]=d[i]=p[i]=D[i]=0,v[i]=false;
	v[A]=1;
	while(t>h){
		x=Q[++h];
		for(i=0;i<E[x].size();i++){
			if(!v[E[x][i]]&&E[x][i]!=B){
				v[E[x][i]]=1;
				Q[++t]=E[x][i];
				p[t]=h;
				d2[t]=d2[h];
				D2[t]=D2[h]+1;
				if(P[x][E[x][i]]){
					e++;
					d2[t]++;}
			}
		}
	}
	for(i=t;i>1;i--){
		D[p[i]]+=D[i];
		d[p[i]]+=d[i]+1;
		if(P[Q[p[i]]][Q[i]])D[p[i]]++;}
	for(i=1;i<=t;i++){
		if(MM>d[i]-D[i]+d2[i]+(t-1-d[i]-D2[i])-(e-D[i]-d2[i])){
			MM=d[i]-D[i]+d2[i]+(t-1-d[i]-D2[i])-(e-D[i]-d2[i]);
		}
	}
	return MM;
}
int main()
{
	int i;
	scanf("%d",&n);
	if(n==1){printf("0\n");return 0;}
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		w[i][0]=a,w[i][1]=b;
		E[a].push_back(b);
		E[b].push_back(a);
		P[a][b]=true;
	}
	int tt;
	Res=n;
	for(i=1;i<n;i++){
		tt=Do(w[i][0],w[i][1])+Do(w[i][1],w[i][0]);
		if(Res>tt)Res=tt;
	}
	printf("%d\n",Res);
}