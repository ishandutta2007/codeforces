#include<cstdio>
#define N 20100
using namespace std;
int a[N],s[N],f[N];
int pre[N],nxt[N];
void add(int x){
	while(x<N){
		f[x]++;
		x+=x&-x;
	}
}
int sum(int x){
	int r=0;
	while(x){
		r+=f[x];
		x-=x&-x;
	}
	return r;
}
int main(){
	int i,j,n,m,t,hh,mm,ss,cut,now,k,R;
	bool flag=false,eq=false;
	scanf("%d%d%d",&n,&m,&t);
	R=n;
	for(i=0;i<n;i++){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		a[i]=hh*3600+mm*60+ss;
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	j=0;
	for(i=0;i<n;i++){
		while(i+1<n&&a[i]==a[i+1]) i++;
		while(a[j]+t<=a[i]) j++;
		cut=i-j+1-sum(i)+sum(j)-m;
		if(cut>=0) eq=true;
		k=i;
		while(cut>0&&k>j){
			pre[nxt[k]]=pre[k];
			s[k]=1;
			R--;
			cut--;
			add(k);
			k=pre[k];
		}
		if(cut>0){
			flag=true;
			break;
		}
	}
	if(flag||!eq){
		puts("No solution");
	}
	else{
		printf("%d\n",R);
		now=0;
		for(i=0;i<n;i++){
			if(s[i]) printf("%d\n",now);
			else printf("%d\n",++now);
		}
	}
	return 0;
}