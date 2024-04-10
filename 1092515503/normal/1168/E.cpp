/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1<<12],lim;
int p[1<<12],P[1<<12],q[1<<12],Q[1<<12];
struct mat{
    int val[1<<12],pos[1<<12],sz;
    void init(){for(int i=0;i<lim;i++)val[i]=pos[i]=i;sz=lim;}
    void era(int x){
        swap(val[x],val[sz-1]);
        pos[val[x]]=x,pos[val[--sz]]=-1;
    }
    int get(int x){return val[x];}
    int fnd(int x){return pos[x];}
    void ins(int x){val[sz]=x,pos[x]=sz++;}
}_p,_o;
mt19937 rnd(17680321);
int main(){
    scanf("%d",&n),lim=1<<n;int sum=0;
    for(int i=0;i<lim;i++)scanf("%d",&a[i]),sum^=a[i];
    if(sum){puts("Fou");return 0;}
    for(int i=0;i<lim;i++)P[i]=Q[i]=p[i]=q[i]=-1;m=lim;
    _o.init(),_p.init();
    while(m){
        int pid=rnd()%_p.sz;
        int _P=_p.get(pid);
        bool fd=false;
        for(int oid=0;oid<_o.sz;oid++)if(Q[_P^a[_o.get(oid)]]==-1){
            int _O=_o.get(oid);
            int _Q=_P^a[_O];
            p[_O]=_P,q[_O]=_Q;
            P[_P]=Q[_Q]=_O;
            _p.era(pid);
            _o.era(oid);
            fd=true,m--;
            break;
        }
        if(fd)continue;
        int oid=rnd()%_o.sz;
        int _O=_o.get(oid);
        int _Q=_P^a[_O];
        int _O2=Q[_Q];
        P[p[_O2]]=Q[q[_O2]]=-1;
        _p.ins(p[_O2]),_o.ins(_O2);
        p[_O2]=q[_O2]=-1;

        p[_O]=_P,q[_O]=_Q;
        P[_P]=Q[_Q]=_O;
        _p.era(_p.fnd(_P));
        _o.era(_o.fnd(_O));
    }
    puts("Shi");
    for(int i=0;i<lim;i++)printf("%d ",p[i]);puts("");
    for(int i=0;i<lim;i++)printf("%d ",q[i]);puts("");
    return 0;
}