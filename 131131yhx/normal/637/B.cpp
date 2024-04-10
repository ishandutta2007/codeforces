#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
namespace prob_b{
	char DBuf[3000000],*DBufCur=DBuf;
	struct str{
		char*s;
		int l;
		inline str(){
			l=0;
			s=NULL;
		}
		inline str(char*x){
			l=strlen(x);
			s=x;
		}
		inline void print(){
			for(int i=0;i<l;++i) putchar(s[i]);
			putchar('\n');
		}
	} sts[200010],*stst=sts;
	inline str DBufStr(str p){
		str t;
		t.s=DBufCur;
		for(t.l=0;t.l<p.l;++t.l) *(DBufCur++)=p.s[t.l];
		return t;
	}
	struct ll{
		ll*l,*r;
		str*t;
	} ss[200010],*Head,NILx,*NIL,*SP=ss;
	inline void init(){
		Head=NIL=&NILx;
	}
	inline void breakLink(ll*p){
		if(p==Head) Head=p->r;
		p->l->r=p->r; p->r->l=p->l;
	}
	inline void putHead(ll*p){
		p->l=NIL,p->r=Head,Head->l=p,Head=p;
	}
	inline void setH(ll*p){
		breakLink(p);
		putHead(p);
	}
	inline ll* sertH(str*e){
		ll*k=SP++;
		k->t=e;
		putHead(k);
		return k;
	}
	struct trie{
		int to[2000000][26],siz;
		ll*Nx[2000000];
		inline ll** add(str p){
			int root=0;
			for(int i=0;i<p.l;++i){
				int t=to[root][p.s[i]-'a']?to[root][p.s[i]-'a']:++siz;
				to[root][p.s[i]-'a']=t;
				root=t;
			}
			return Nx+root;
		}
	} ttt;
} using namespace prob_b;
char sp[20];
int main(){
	int n,m; scanf("%d",&n); m=n;
	init();
	while(n--){
		scanf("%s",sp);
		str tx(sp);
		ll** vex=ttt.add(tx);
		if(*vex)setH(*vex);
		else *vex=sertH(&(*(stst++)=DBufStr(tx)));
	}
	int cnt=0;
	for(ll*p=Head;p!=NIL;p=p->r){
		++cnt;
		p->t->print();
	}
	return 0;
}