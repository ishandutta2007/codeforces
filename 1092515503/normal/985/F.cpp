#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
int p1[200100],p2[200100],n,m,m1=19260817,m2=666623333;
void operator +=(pii &u,const int ip){
	u.x=((u.x<<1)+ip)%m1;
	u.y=((u.y<<1)+ip)%m2;
}
pii hs[200100][26],p[26],q[26];
pii gt(int l,int r,int op){
	return mp((hs[r][op].x-(1ll*hs[l][op].x*p1[r-l]%m1)+m1)%m1,(hs[r][op].y-(1ll*hs[l][op].y*p2[r-l]%m2)+m2)%m2);
}
char s[200100];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	p1[0]=p2[0]=1;
	for(int i=1;i<=n;i++)p1[i]=(p1[i-1]<<1)%m1,p2[i]=(p2[i-1]<<1)%m2;
	for(int i=1;i<=n;i++)for(int j=0;j<26;j++)hs[i][j]=hs[i-1][j],hs[i][j]+=(s[i]-'a'==j);
//	for(int i=0;i<26;i++){for(int j=1;j<=n;j++)printf("(%d,%d)",hs[j][i].x,hs[j][i].y);puts("");}
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		for(int j=0;j<26;j++)p[j]=gt(a-1,a+c-1,j),q[j]=gt(b-1,b+c-1,j);
		sort(p,p+26),sort(q,q+26);
		bool ok=true;
		for(int j=0;j<26;j++){
//			printf("(%d,%d)(%d,%d)\n",p[j].x,p[j].y,q[j].x,q[j].y);
			if(p[j]!=q[j]){ok=false;break;}
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}