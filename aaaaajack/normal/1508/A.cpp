#include<bits/stdc++.h>
using namespace std;
char s[3][200100];
int pos[200100];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,cnt[3]={},x,y;
		scanf("%d",&n);
		n*=2;
		for(int i=0;i<3;i++){
			scanf("%s",s[i]);
			for(int j=0;j<n;j++){	
				cnt[i]+=s[i][j]-'0';
			}
			if(cnt[i]>n/2) cnt[i]=1;
			else cnt[i]=0;
		}
		if(cnt[0]==cnt[1]) x=0,y=1;
		else if(cnt[0]==cnt[2]) x=0,y=2;
		else x=1,y=2;
		char g='0'+cnt[x];
		int cx=0,cy=0;
		for(int i=0;i<=n;i++) pos[i]=0;
		for(int i=0;i<n;i++){
			if(s[x][i]==g) cx++;
			else pos[cx]++;
			if(s[y][i]==g) cy++;
			else pos[cy]++;
		}
		for(int i=0;i<=max(cx,cy);i++){
			for(int j=0;j<pos[i];j++) putchar('0'+(1-cnt[x]));
			if(i<max(cx,cy))putchar(g);
		}
		puts("");
	}
	return 0;
}