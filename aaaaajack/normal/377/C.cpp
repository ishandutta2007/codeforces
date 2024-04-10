#include<cstdio>
#include<algorithm>
#include<functional>
#define inf (0x7fffffff)
using namespace std;
int t1[20][1<<20],t2[20][1<<20];
char act[20];
int team[21],str[100];
int find_min(int,int,int);
int find_max(int now,int m,int hero){
	if(now==m) return 0;
	if(t1[now][hero]!=inf) return t1[now][hero];
	int Max=-inf,i,king;
	for(i=0;i<m;i++){
		if(hero&(1<<i)){
			king=i;
			break;
		}
	}
	if(team[now+1]==1){
		if(act[now]=='p') Max=str[king]+find_max(now+1,m,hero^(hero&-hero));
		else{
			for(i=0;i<m;i++){
				if(hero&(1<<i)){
					if(find_max(now+1,m,hero&~(1<<i))>Max) Max=find_max(now+1,m,hero&~(1<<i));
				}
			}
		}
	}
	else{
		if(act[now]=='p') Max=str[king]+find_min(now+1,m,hero^(hero&-hero));
		else{
			for(i=0;i<m;i++){
				if(hero&(1<<i)){
					if(find_min(now+1,m,hero&~(1<<i))>Max) Max=find_min(now+1,m,hero&~(1<<i));
				}
			}
		}
	}
	return t1[now][hero]=Max;			
}
int find_min(int now,int m,int hero){
	if(now==m) return 0;
	if(t2[now][hero]!=inf) return t2[now][hero];
	int Min=inf,i,king;
	for(i=0;i<m;i++){
		if(hero&(1<<i)){
			king=i;
			break;
		}
	}
	if(team[now+1]==1){
		if(act[now]=='p') Min=-str[king]+find_max(now+1,m,hero^(hero&-hero));
		else{
			for(i=0;i<m;i++){
				if(hero&(1<<i)){
					if(find_max(now+1,m,hero&~(1<<i))<Min) Min=find_max(now+1,m,hero&~(1<<i));
				}
			}
		}
	}
	else{
		if(act[now]=='p') Min=-str[king]+find_min(now+1,m,hero^(hero&-hero));
		else{
			for(i=0;i<m;i++){
				if(hero&(1<<i)){
					if(find_min(now+1,m,hero&~(1<<i))<Min) Min=find_min(now+1,m,hero&~(1<<i));
				}
			}
		}
	}
	return t2[now][hero]=Min;			
}
int main(){
	int i,j,n,m;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&str[i]);
	sort(str,str+n,greater<int>());
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf(" %c %d",&act[i],&team[i]);
	}
	for(i=0;i<m;i++){
		for(j=0;j<(1<<m);j++){
			t1[i][j]=t2[i][j]=inf;
		}
	}
	team[m]=1;
	if(team[0]==1){
		printf("%d\n",find_max(0,m,(1<<m)-1));
	}
	else{
		printf("%d\n",find_min(0,m,(1<<m)-1));
	}
	return 0;
}