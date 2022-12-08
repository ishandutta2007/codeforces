#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e2+5;

int T;
int n,m;
int a[N][N];
int b[N][N];
int fx[4]={0,0,-1,1};
int fy[4]={-1,1,0,0};

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		bool flag=0;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			int c=0;
			for(int k=0;k<4;++k){
				int x=i+fx[k],y=j+fy[k];
				if(x<1||x>n||y<1||y>m)continue;
				++c;
			}
			if(c<a[i][j]){
				flag=1;
			}
		}
		if(flag){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int c=4;
				if(j==1||j==m)c--;
				if(i==1||i==n)c--;
				printf("%d ",c);
			}
			printf("\n");
		}
	}
}