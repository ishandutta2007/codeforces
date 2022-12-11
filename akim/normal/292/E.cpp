#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
typedef struct item * treap;
struct item
{
 int key,cnt,prior,lg;
 bool izm;
 treap l,r;
 void init(int k){izm=0;l=r=0;key=k;cnt=1;prior=rand();}
};
int x[100100]={0};
int cnt(treap t){return(t?t->cnt:0);}
void upd(treap t){if(t){t->cnt=cnt(t->l)+cnt(t->r)+1;}}
void push(treap t)
{
 if(t&&t->izm)
 {
  t->izm=0;
  t->key=x[t->lg+cnt(t->l)];
  if(t->l){t->l->izm=1;t->l->lg=t->lg;}
  if(t->r){t->r->izm=1;t->r->lg=t->lg+cnt(t->l)+1;}
 }
}
treap merge(treap l,treap r)
{push(l);push(r);
 if(!l||!r){return(l?l:r);}
 if(l->prior > r->prior){l->r=merge(l->r,r);upd(l);return(l);}
                    else{r->l=merge(l,r->l);upd(r);return(r);}
}
void split(treap t,treap &l,treap &r,int key)
{
 if(!t){l=r=0;return;}
 push(t);
 int ckey=cnt(t->l)+1;
 if(ckey>key){split(t->l,l,t->l,key);r=t;}
         else{split(t->r,t->r,r,key-ckey);l=t;}
 upd(l);upd(r);
}
void out(treap t,int key)
{push(t);
 int ckey=cnt(t->l)+1;
 if(key==ckey){printf("%d\n",t->key);return;}
 if(ckey>key){out(t->l,key);}
         else{out(t->r,key-ckey);}
}
void out2(treap t)
{
 if(!t){return;}
 push(t);
 out2(t->l);
 printf("%d ",t->key);
 out2(t->r);
}
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 treap t=0;
 int n,m,i;
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++){scanf("%d",&x[i]);}
 for(i=1;i<=n;i++){int u;scanf("%d",&u);treap t1=new item;t1->init(u);t=merge(t,t1);}
 for(;m>0;m--)
 {int w;
  scanf("%d",&w);
  if(w==1){int pl,pr,k;
           scanf("%d%d%d",&pl,&pr,&k);
           treap t1,t2,t3,t4,t5,t6,t7,t8;
           split(t,t1,t2,pr-1);
           split(t2,t3,t4,k);
           t3->izm=1;t3->lg=pl;
           t=merge(t1,merge(t3,t4));
//           out2(t);printf("\n");
          }else
          {int u;
           scanf("%d",&u);
           out(t,u);
          }
 }
}