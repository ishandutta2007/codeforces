/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int phi=mod-1;
int ksm(int x,int y=phi-1){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int msk(int x,int y){int z=1;for(;y;y>>=1,x=1ll*x*x%phi)if(y&1)z=1ll*z*x%phi;return z;}
struct dat{
int val,ten;
dat(){val=0,ten=1;}
dat(int V,int T){val=V,ten=T;}
friend dat operator+(const dat&u,const dat&v){return dat((1ll*u.val*v.ten+v.val)%mod,1ll*u.ten*v.ten%mod);}
friend dat operator-(const dat&u,const dat&v){
	dat w;
	w.ten=1ll*u.ten*ksm(v.ten)%mod;
	w.val=(u.val+mod-1ll*v.val*w.ten%mod)%mod;
	return w;
}
void print()const{printf("[%d,%d]",val,ten);}
}f[100100];
dat ksm(dat x,int y){dat z;for(;y;y>>=1,x=x+x)if(y&1)z=z+x;return z;}
dat KSM(char*l,char*r,dat d){
	static dat pov[10];for(int i=1;i<10;i++)pov[i]=pov[i-1]+d;
	dat ret;
	while(l!=r)ret=ksm(ret,10)+pov[*(l++)-'0'];
	return ret;
}
dat gene(char*l,char*r){
	dat ret;ret.ten=ksm(10,r-l);
	while(l!=r)ret.val=(10ll*ret.val+*(l++)-'0')%mod;
	return ret;
}
int stereotype(int a,int modn,int phin){
	// printf("STER:%d,%d,%d\n",a,modn,phin);
	int an=ksm(a,phin);
	int ia1=ksm((a+mod-1)%mod);
	return (1ll*(modn+mod-1)*an-1ll*(an+mod-1)*ia1%mod+mod+1)%mod*ia1%mod;
}
dat conca(char*l,char*r){
	int modn=0,phin=0;
	for(char*i=l;i!=r;i++)modn=(10ll*modn+(*i-'0'))%mod,phin=(10ll*phin+(*i-'0'))%phi;
	(++modn)%=mod,(++phin)%=phi;
	int i=r-l-1;
	int fv=stereotype(ksm(10,phi-(i+1)),modn,phin);
	int rv=stereotype(ksm(10,phi-(i+1)),ksm(10,i),msk(10,i));
	int val=1ll*(fv+mod-rv)*ksm(ksm(10,i+1),(phin+phi-1)%phi)%mod;
	int ten=ksm(ksm(10,i+1),(phin+phi-msk(10,i))%phi);
	// for(char*i=l;i!=r;i++)putchar(*i);printf(":"),(f[i]+dat(val,ten)).print();puts("");
	return f[i]+dat(val,ten);
}
int S,mat[100100],stk[100100],tp;
char s[100100];
dat solve(int l,int r){
	// printf("SOLVE:[%d,%d]",l,r);for(int i=l;i<r;i++)putchar(s[i]);puts("");
	if(l>=r)return dat();
	int p=l;while(s[p]>='0'&&s[p]<='9')p++;
	if(p==r)return gene(s+l,s+r);
	if(s[p]=='(')return KSM(s+l,s+p,solve(p+1,mat[p]))+solve(mat[p]+2,r);
	if(s[p]=='+')return gene(s+l,s+p)+solve(p+1,r);
	if(s[p]=='-'){
		int q=p+1;
		while(s[q]>='0'&&s[q]<='9')q++;
		return (gene(s+l,s+p)+(conca(s+p+1,s+q)-conca(s+l,s+p)))+solve(q+1,r);
	}
}
int main(){
	scanf("%s",s),S=strlen(s);
	for(int i=0;i<S;i++){
		int fv=stereotype(ksm(10,phi-(i+1)),ksm(10,i+1),msk(10,i+1));
		int rv=stereotype(ksm(10,phi-(i+1)),ksm(10,i),msk(10,i));
		int val=1ll*(fv+mod-rv)*ksm(ksm(10,i+1),(msk(10,i+1)+phi-1)%phi)%mod;
		int ten=ksm(ksm(10,i+1),(msk(10,i+1)+phi-msk(10,i))%phi);
		f[i+1]=f[i]+dat(val,ten);
	}
	for(int i=0;i<S;i++){
		if(s[i]=='(')stk[++tp]=i;
		if(s[i]==')')mat[stk[tp]]=i,mat[i]=stk[tp--];
	}
	printf("%d\n",solve(0,S).val);
	return 0;
}