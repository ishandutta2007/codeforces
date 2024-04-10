#include<bits/stdc++.h>
#define N 5010
using namespace std;
int a[N][N];
bool b[N][N];
char s[N];
int main(){
	int n;
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		for(int j=0;j+i<n;j++){
			if(i) a[j][i+j]+=a[j][i+j-1]+a[j+1][i+j];
			if(i>1) a[j][i+j]-=a[j+1][i+j-1];
			if(i==0) a[j][j]=b[j][j]=1;
			else if(s[j]==s[j+i]&&(i==1||b[j+1][j+i-1])){
				a[j][j+i]++;
				b[j][j+i]=1;
			}
		}
	}
	int q,l,r;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r);
		l--,r--;
		printf("%d\n",a[l][r]);
	}
	return 0;
}