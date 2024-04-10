#include<bits/stdc++.h>
char s[100][100];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		bool bla=false,ca=false,la=false,ba=false,ex=false,np=true;
		for(int i=0;i<n;i++){
			bool line=true;
			for(int j=0;j<m;j++){
				if(s[i][j]=='A'){
					ex=true;
					if((i==0||i==n-1)&&(j==0||j==m-1))  ca=true;
					if(i==0||i==n-1||j==0||j==m-1) ba=true;
				}
				else{
				    line=false;
				    np=false;
				}
			}
			if(line){
				la=true;
				if(i==0||i==n-1) bla=true;
			}
		}
		for(int j=0;j<m;j++){
			bool line=true;
			for(int i=0;i<n;i++){
				if(s[i][j]=='P') line=false;
			}
			if(line){
				la=true;
				if(j==0||j==m-1) bla=true;
			}
		}
		if(np) puts("0");
		else if(bla) puts("1");
		else if(ca||la) puts("2");
		else if(ba) puts("3");
		else if(ex) puts("4");
		else puts("MORTAL");
	}
	return 0;
}