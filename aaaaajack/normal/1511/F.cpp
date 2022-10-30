#include<bits/stdc++.h>
#define Q 998244353
#define S 240
using namespace std;
void sq(int mat[S][S]){
	long long tmp[S][S]={};
	for(int i=0;i<S;i++){
		for(int j=0;j<S;j++){
			for(int k=0;k<S;k++){
				tmp[i][j]+=1LL*mat[i][k]*mat[k][j]%Q;
			}
		}
	}
	for(int i=0;i<S;i++){
		for(int j=0;j<S;j++){
			mat[i][j]=tmp[i][j]%Q;
		}
	}
}
void mult_vec(int mat[][S], int v[]){
	long long tmp[S]={};
	for(int i=0;i<S;i++){
		for(int j=0;j<S;j++){
			tmp[i]+=1LL*mat[i][j]*v[j]%Q;
		}
	}
	for(int i=0;i<S;i++) v[i]=tmp[i]%Q;
}
int main(){
	int n,m;
	int mat[S][S]={}; //total_length*belonging*gap, 8*6
	char s[10][6];
	int sl[10];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",s[i]),sl[i]=strlen(s[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<=sl[i];j++){
			for(int k=0;k<n;k++){
				bool flag=true;
				for(int l=0;j+l<sl[i] && l<sl[k];l++){
					if(s[i][j+l]!=s[k][l]) flag=false;
				}
				if(flag){
					int st=(sl[k]-1)*48+i*6+(sl[i]-j),ed;
					if(sl[k]<sl[i]-j){
						ed=i*6+(sl[i]-j-sl[k]);
					}
					else{
						ed=k*6+(sl[k]-sl[i]+j);
					}
					mat[ed][st]++;
				}
			}
		}
	}
	for(int i=48;i<S;i++) mat[i][i-48]++;
	int v[S]={1};
	int expo=m*2;
	while(expo){
		if(expo&1) mult_vec(mat,v);
		sq(mat);
		expo>>=1;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=(ans+v[i*6])%Q;
	}
	printf("%d\n",ans);
	return 0;
}