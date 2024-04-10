#include<bits/stdc++.h>
using namespace std;
const int bs1=17680321;
const int bs2=19260817;
const int bs3=19491001;
int n,m,LR,BT,LT,TR,RB,BL,a[400100],col[400100],p;
bool vis[400100];
vector<int>v[400100],u[400100];
char s[10];
void V(int x,int y){v[x].push_back(y),v[y].push_back(x);}
void U(int x,int y){u[x].push_back(y),u[y].push_back(x);}
struct circ{
	int st,nx,len,bs1,bs2,bs3;
	circ(int A,int B,int C,int D,int E,int F){st=A,nx=B,len=C,bs1=D,bs2=E,bs3=F;}
	friend bool operator<(const circ&x,const circ&y){
		if(x.len!=y.len)return x.len<y.len;
		if(x.bs1!=y.bs1)return x.bs1<y.bs1;
		if(x.bs2!=y.bs2)return x.bs2<y.bs2;
		return x.bs3<y.bs3;
	}
};
vector<circ>uu,vv;
circ HS(){
	int i=0,j=1,k=0;
	while(i<p&&j<p&&k<p){
		if(col[a[(i+k)%p]]==col[a[(j+k)%p]])k++;
		else{
			if(col[a[(i+k)%p]]>col[a[(j+k)%p]])i+=k+1;else j+=k+1;
			if(i==j)i++;
			k=0;
		}
	}
	int I=p-min(i,j)-1;
	i=0,j=1,k=0;
	reverse(a,a+p);
	while(i<p&&j<p&&k<p){
		if(col[a[(i+k)%p]]==col[a[(j+k)%p]])k++;
		else{
			if(col[a[(i+k)%p]]>col[a[(j+k)%p]])i+=k+1;else j+=k+1;
			if(i==j)i++;
			k=0;
		}
	}
	int J=min(i,j);
//	printf(" %d %d\n",I,J);
	for(k=0;k<p;k++){
		if(col[a[(I+p-k)%p]]==col[a[(J+k)%p]])continue;
		if(col[a[(I+p-k)%p]]<col[a[(J+k)%p]]){
			int r1=0,r2=0,r3=0;
			for(k=0;k<p;k++){
				r1=(4*r1+col[a[(I+p-k)%p]])%bs1;
				r2=(4*r2+col[a[(I+p-k)%p]])%bs2;
				r3=(4*r3+col[a[(I+p-k)%p]])%bs3;
			}
			return circ(a[I],a[(I+p-1)%p],p,r1,r2,r3);
		}else{
			int r1=0,r2=0,r3=0;
			for(k=0;k<p;k++){
				r1=(4*r1+col[a[(J+k)%p]])%bs1;
				r2=(4*r2+col[a[(J+k)%p]])%bs2;
				r3=(4*r3+col[a[(J+k)%p]])%bs3;
			}
			return circ(a[J],a[(J+1)%p],p,r1,r2,r3);
		}
	}
	int r1=0,r2=0,r3=0;
	for(k=0;k<p;k++){
		r1=(4*r1+col[a[(I+p-k)%p]])%bs1;
		r2=(4*r2+col[a[(I+p-k)%p]])%bs2;
		r3=(4*r3+col[a[(I+p-k)%p]])%bs3;
	}
	return circ(a[I],a[(I+p-1)%p],p,r1,r2,r3);
}
void dfs(vector<int>*w,int x){
	if(vis[x])return;
	vis[x]=true,a[p++]=x;
//	printf("%d",col[x]);
	for(auto y:w[x])dfs(w,y);
}
int UU[100100],VV[100100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)col[i]=0;
	for(int i=n+1;i<=n+m;i++)col[i]=1;
	for(int i=n+m+1;i<=2*n+m;i++)col[i]=2;
	for(int i=2*n+m+1;i<=2*n+2*m;i++)col[i]=3;
	for(int i=1,x,y;i<=n+m;i++){
		scanf("%s%s%d%d",s,s+1,&x,&y);
		if(s[0]=='L')x+=0;
		if(s[0]=='T')x+=n;
		if(s[0]=='R')x+=n+m;
		if(s[0]=='B')x+=2*n+m;
		if(s[1]=='L')y+=0;
		if(s[1]=='T')y+=n;
		if(s[1]=='R')y+=n+m;
		if(s[1]=='B')y+=2*n+m;
		V(x,y);
		if(s[0]=='L'&&s[1]=='R'||s[1]=='L'&&s[0]=='R')LR++;
		if(s[0]=='B'&&s[1]=='T'||s[1]=='B'&&s[0]=='T')BT++;
		if(s[0]=='L'&&s[1]=='T'||s[1]=='L'&&s[0]=='T')LT++,U(LT,n+LT);
		if(s[0]=='T'&&s[1]=='R'||s[1]=='T'&&s[0]=='R')TR++,U(n+m-TR+1,n+m+TR);
		if(s[0]=='R'&&s[1]=='B'||s[1]=='R'&&s[0]=='B')RB++,U(2*n+m-RB+1,2*n+2*m-RB+1);
		if(s[0]=='B'&&s[1]=='L'||s[1]=='B'&&s[0]=='L')BL++,U(2*n+m+BL,n-BL+1);
	}
	if(LR&&BT)return puts("No solution"),0;
	for(int i=1;i<=LR;i++)U(LT+i,n+m+TR+i);
	for(int i=1;i<=BT;i++)U(n+LT+i,2*n+m+BL+i);
	for(int i=1;i<=n;i++)V(i,n+m+i),U(i,n+m+i);
	for(int i=n+1;i<=n+m;i++)V(i,n+m+i),U(i,n+m+i);
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=2*n+2*m;i++){
		if(vis[i])continue;
		p=0,dfs(v,i);
		vv.push_back(HS());
//		puts("");
	}
//	puts("");
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=2*n+2*m;i++){
		if(vis[i])continue;
		p=0,dfs(u,i);
		uu.push_back(HS());
//		puts("");
	}
//	puts("");
	sort(vv.begin(),vv.end());
	sort(uu.begin(),uu.end());
	if(vv.size()!=uu.size())return puts("No solution"),0;
	for(int i=0;i<vv.size();i++)if(vv[i]<uu[i]||uu[i]<vv[i])return puts("No solution"),0;
	for(int i=0;i<vv.size();i++){
		int x=vv[i].st,y=uu[i].st;
		int X=v[x][0]^v[x][1]^vv[i].nx;
		int Y=u[y][0]^u[y][1]^uu[i].nx;
		for(int j=0;j<vv[i].len;j++,X=v[x][0]^v[x][1]^X,Y=u[y][0]^u[y][1]^Y,swap(x,X),swap(y,Y)){
//			printf("(%d %d):(%d,%d)\n",col[x],col[y],x,y);
			if(col[x]==0)UU[y]=x;
			if(col[x]==1)VV[y-n]=x-n;
			if(col[x]==2)UU[y-n-m]=x-n-m;
			if(col[x]==3)VV[y-2*n-m]=x-2*n-m;
		}
//		puts("");
	}
	for(int i=1;i<=n;i++)printf("%d ",UU[i]);puts("");
	for(int i=1;i<=m;i++)printf("%d ",VV[i]);puts("");
	return 0;
}