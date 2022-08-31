#include<stdio.h>
#include<string.h>
char p[1510],q[28];
bool v[1510][1510];
int n,m,i,j,k,bad,R,oto[1510],t,L;
int main()
{
	scanf("%s%s%d",p,q,&m);
	n=strlen(p);
	for(i=0;i<n;i++){
		bad=0;
		k=i;
		oto[0]=-1;
		for(j=0;j<n-i;j++){
			bad+='1'-q[p[i+j]-'a'];
			if(bad>m)break;
			if(!v[i][j])R++;
			if(k==n)continue;
			t=oto[j];
			while(t!=-1&&p[i+j]!=p[i+t])t=oto[t];
			oto[j+1]=t+1;
			L=j-1;
			while(k<n&&L<j){
				L++,k++;
				while(k<n && p[k]!=p[i+L]){
					L=oto[L];
					if(L==-1)L++,k++;
				}
			}
			if(k<n)v[k-j][j]=true;
		}
	}
	printf("%d\n",R);
}