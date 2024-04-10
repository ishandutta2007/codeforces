#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[60][60];
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		int c=-1,tc;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='.') continue;
				if(s[i][j]=='R') tc=(i+j)&1;
				else tc=((i+j)&1)^1;
				if(c<0) c=tc;
				else if(tc!=c) c=2;
				else c=tc;
			}
		}
		if(c<0) c=0;
		if(c==2) puts("NO");
		else{
			puts("YES");
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(((i+j)&1)==c) s[i][j]='R';
					else s[i][j]='W';
				}
				puts(s[i]);
			}
		}
	}
	return 0;
}