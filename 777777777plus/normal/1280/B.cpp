#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 60+5;

int T;
int n,m;
char s[N][N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		bool p=0,a=0;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(s[i][j]=='A')a=1;
			if(s[i][j]=='P')p=1;
		}
		if(!a){
			puts("MORTAL");
			continue;
		}
		else if(!p){
			puts("0");
			continue;
		}
		bool flag=0,flag1=0,flag2=0;
		for(int i=1;i<=n;++i){
			bool line=1;
			for(int j=1;j<=m;++j)if(s[i][j]!='A')line=0;
			if(line){
				if(i==1||i==n)flag1=1;
				else flag2=1;
			}
		}
		for(int i=1;i<=m;++i){
			bool line=1;
			for(int j=1;j<=n;++j)if(s[j][i]!='A')line=0;
			if(line){
				if(i==1||i==m)flag1=1;
				else flag2=1;
			}
		}
		if(flag1){
			puts("1");
			continue;
		}
		if(flag2||s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A'){
			puts("2");
			continue;
		}
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		if(s[i][j]=='A'){
			if(i==1||i==n||j==1||j==m)flag=1;
		}
		if(flag){
			puts("3");
			continue;
		}
		puts("4");
	}
}