#include<bits/stdc++.h>
using namespace std;
const int N = 333333;
int n,x,y,z;
char a[N],b[N],c[N];
int main(){
	int T,i,j,o,w;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s%s",&n,a+1,b+1,c+1);
		x=0,y=0,z=0;
		for(i=1;i<=n*2;i++)
			x+=a[i]-'0',y+=b[i]-'0',z+=c[i]-'0';
		
		if(x>y){
			for(i=1;i<=n*2;i++)swap(a[i],b[i]);
			swap(x,y);
		}
		if(x>z){
			for(i=1;i<=n*2;i++)swap(a[i],c[i]);
			swap(x,z);
		}
		if(y>z){
			for(i=1;i<=n*2;i++)swap(b[i],c[i]);
			swap(y,z);
		}
		if(y<=n){
			o='0';
		}
		else{
			o='1';
			for(i=1;i<=n*2;i++)swap(a[i],c[i]);
			swap(x,z);
		}
		w=0;
		for(i=1,j=1;i<=n*2||j<=n*2;){
			if(w<n&&a[i]==o&&b[j]==o)
				printf("%c",o),i++,j++,w++;
			else{
				while(i<=n*2&&(a[i]!=o||w>=n))
					printf("%c",a[i]),i++;
				while(j<=n*2&&(b[j]!=o||w>=n))
					printf("%c",b[j]),j++;
			}
		}
		printf("\n");
	}
	return 0;
}