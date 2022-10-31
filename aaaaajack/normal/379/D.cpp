#include<cstdio>
using namespace std;
int main(){
	int count[51];
	bool f[51],b[51],flag=false;
	char s1[200],s2[200];
	int k,x,n,m,i,j,l,t;
	scanf("%d%d%d%d",&k,&x,&n,&m);
	s1[n]=0;
	s2[m]=0;
	for(i=0;i<n;i++) s1[i]='B';
	for(i=0;i<m;i++) s2[i]='B';
	for(i=0;i<=n/2;i++){
		for(j=0;j<=m/2;j++){
			for(t=0;t<16;t++){
				int temp1=2*i,temp2=2*j;
				if(t&1) f[1]=true,temp1++;
				else f[1]=false;
				if(t&2) b[1]=true,temp1++;
				else b[1]=false;
				if(t&4) f[2]=true,temp2++;
				else f[2]=false;
				if(t&8) b[2]=true,temp2++;
				else b[2]=false;
				if(temp1>n||temp2>m) continue;
				count[1]=i;
				count[2]=j;
				for(l=3;l<=k;l++){
					count[l]=count[l-1]+count[l-2];
					if(f[l-1]&&b[l-2]) count[l]++; 
					f[l]=f[l-2];
					b[l]=b[l-1];
					if(count[l]>x) break;
				}
				if(l==k+1&&count[k]==x){
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag){
		int start=0;
		if(t&1) s1[0]='C',start++;
		if(t&2) s1[n-1]='A';
		for(l=0;l<i;l++){
			s1[start++]='A';
			s1[start++]='C';
		}
		start=0;
		if(t&4) s2[0]='C',start++;
		if(t&8) s2[m-1]='A';
		for(l=0;l<j;l++){
			s2[start++]='A';
			s2[start++]='C';
		}
		printf("%s\n%s\n",s1,s2);
	}
	else{
		puts("Happy new year!");
	}
	return 0;
}