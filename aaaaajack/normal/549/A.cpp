#include<cstdio>
using namespace std;
char s[100][100];
int main(){
	int n,m,i,j,cnt=0;
	bool face[128];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%s",s[i]);
	for(i=0;i<n-1;i++){
		for(j=0;j<m-1;j++){
			face['f']=face['a']=face['c']=face['e']=false;
			face[s[i][j]]=face[s[i+1][j]]=face[s[i][j+1]]=face[s[i+1][j+1]]=true;
			if(face['f']&&face['a']&&face['c']&&face['e']) cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}