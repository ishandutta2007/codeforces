#include<bits/stdc++.h> 
using namespace std;
int n,m,a[100100];
char s[4];
void singlesolution(){
	for(int i=1;i<n;i++)printf("%d%c",a[i],s[0]);
	printf("%d\n",a[n]);
	exit(0);
}
void minusplussolution(){
	for(int i=1;i<n;i++)printf("%d%c",a[i],'+');
	printf("%d\n",a[n]);
	exit(0);
}
void minustimessolution(){
	int i=1;
	for(;i<n;i++)if((a[i]>=1)&&(a[i+1]>=1))printf("%d%c",a[i],'*');else{
		if(i==1&&(a[i]==0))printf("%d%c",a[i],'*');
		else printf("%d%c",a[i],'-');
		i++;
		break;
	}
	for(;i<n;i++)printf("%d%c",a[i],'*');
	printf("%d\n",a[i]);
	exit(0);
}
int f[1010],g[1010],b[1010],c[1010],p,pro[1010];
char t[100100];
const int inf=0x3f3f3f3f;
struct node{
	int st,ed,val;
	bool tp;
	node(int x,int y,int z,int w){st=x,ed=y,val=z,tp=w;} 
};
vector<node>v;
void plustimessolution(){
	for(int i=1,j=1;i<=n;i=j){
		if(!a[i]){t[i]='+',j++;continue;}
		if(a[i]==1){
			while(j<=n&&a[j]==1)j++;
			if(j<=n&&!a[j])t[j-1]='+';
			v.push_back(node(i,j,j-i,1));
			continue;
		}
		while(j<=n&&a[j]>1)j++;
		if(j<=n&&!a[j])t[j-1]='+';
		int val=1;
		for(int k=i;k<j;k++)val=min(1ll*inf,1ll*val*a[k]);
		v.push_back(node(i,j,val,0));
	}
//	for(int i=1;i<n;i++)printf("%d%c",a[i],t[i]);printf("%d\n",a[n]); 
//	for(auto i:v)printf("%d %d %d %d\n",i.st,i.ed,i.val,i.tp);
	for(int i=0,j=0;i<v.size();i=j){
		if(v[i].tp){
			for(int k=v[i].st;k<=v[i].ed;k++)t[k-1]='+';
			j++;continue;
		}
		j++;
		while(j<v.size()&&v[j-1].ed==v[j].st)j++;
		int delta=0;
		if(v[j-1].tp){
			j--;
			for(int k=v[j].st;k<=v[j].ed;k++)t[k-1]='+';
		}
		int all=1;
		for(int k=i;k<j;k++)if(!v[k].tp)all=min(1ll*inf,1ll*all*v[k].val);
		if(all==inf)for(int k=v[i].st;k+1<v[j-1].ed;k++)t[k]='*';
		else{
			p=0;
			for(int k=i;k<j;k++){
				if((k&1)==(i&1))b[++p]=v[k].val;
				else c[p]=v[k].val;
			}
//			for(int k=1;k<=p;k++)printf("%d ",b[k]);puts("");
//			for(int k=1;k<p;k++)printf("%d ",c[k]);puts("");puts("");
			pro[0]=1;
			for(int k=1;k<=p;k++)pro[k]=pro[k-1]*b[k];
			for(int r=1;r<=p;r++){
				f[r]=pro[r],g[r]=0;
				for(int l=1;l<r;l++)if(f[l]+pro[r]/pro[l]+c[l]>f[r])f[r]=f[l]+pro[r]/pro[l]+c[l],g[r]=l;
			}
			for(int k=p;k;k=g[k]){
				for(int l=v[i+g[k]*2].st;l+1<v[i+(k-1)*2].ed;l++)t[l]='*';
				if(g[k])for(int l=v[i+g[k]*2-1].st;l<=v[i+g[k]*2-1].ed;l++)t[l-1]='+';
			}
		}
		j+=delta;
	}
	for(int i=1;i<n;i++)printf("%d%c",a[i],t[i]);printf("%d\n",a[n]); 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%s",s),m=strlen(s);
	sort(s,s+m);
	if(m==1)singlesolution();
	if(m==2){
		if(s[0]=='*'&&s[1]=='+')plustimessolution();
		if(s[0]=='*'&&s[1]=='-')minustimessolution();
		if(s[0]=='+'&&s[1]=='-')minusplussolution();
	}
	if(m==3)plustimessolution();
	return 0;
}
/*
21
0 0 2 2 2 1 1 2 1 1 1 0 0 2 2 1 1 2 2 1 0
*+
*/