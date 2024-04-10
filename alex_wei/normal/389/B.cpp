#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,dx[5]={0,1,1,1,2},dy[5]={0,-1,0,1,0};
char c[102][102];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>c[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]=='#'){
				if(i>=n-1||j==1||j==n)puts("NO"),exit(0);
				for(int k=0;k<5;k++){
					if(c[i+dx[k]][j+dy[k]]!='#')puts("NO"),exit(0);
					c[i+dx[k]][j+dy[k]]='.';
				}
			}
		}
	}
	puts("YES");
    return 0;
}