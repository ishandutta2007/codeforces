#include<bits/stdc++.h>
using namespace std;
const int N = 444444;
int n,a[N],f[N],b[N],g[N];
int main(){
	int i,x,y,o,s,t,u;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if((x<=n)==(y<=n)){
			printf("-1");
			return 0;
		}
		a[x]=y,a[y]=x;
		f[x]=(x<y),f[y]=(x<y);
	}
	for(i=1;i<=n;i++)
		b[i]=a[n+i];
	x=n+1,y=n+1;
	o=1;
	u=0;
	for(i=1;i<=n;i++){
		if(b[i]>y){
			printf("-1");
			return 0;
		}
		if(b[i]>x){
			y=min(y,b[i]);
			g[i]=1;
		}
		else{
			x=b[i];
			g[i]=0;
		}
		if(x==n-i+1){
			s=0,t=0;
			while(o<=i){
				if(f[b[o]]==g[o])
					s++;
				else
					t++;
				o++;
			}
			u+=min(s,t);
		}
	}
	printf("%d",u);
	return 0;
}