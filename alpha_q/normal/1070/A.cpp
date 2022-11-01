#include<bits/stdc++.h>
using namespace std;

typedef long long lala;
typedef pair<int,int> pii;

//constants
#define Pi acos(-1.0)
#define INF INT_MAX ///check it again
#define mod 1000000007ll

#define D(x) cout << #x " = "<<(x)<<endl

#define xx first
#define yy second

#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)

#define pi(a) printf("%d\n",a)
#define psi(a) printf(" %d",a)
#define poi(a) printf("%d",a)

#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)

#define Nline() printf("\n")

#define sstr(str) scanf("%s",str)
#define pstr(str) printf("%s\n",str)

#define fin() freopen("in.txt","r",stdin)
#define fout() freopen("out.txt","w",stdout)

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

#define mx 5009

pii pr[509][5009];
bool vs[509][5009];
pii inf;
void bfs(int d, int s)
{
    queue<pii>qu;
    pii u,v;
    inf=make_pair(-1,-1);
    int i;
    vs[0][s]=1;
    pr[0][s]=inf;
    qu.push(make_pair(0,s));
    int md=d;
    int S=s;
    int p,q;
    while(!qu.empty()){
        u=qu.front();
        qu.pop();
        d=u.xx;
        s=u.yy;
        //printf("%d %d.\n",d,s);
        if(d==0 && s==0)return;
        for(i=0;i<10;i++){
            p=(d*10+i)%md;
            q=s-i;
            if(q>=0 && !vs[p][q]){
                vs[p][q]=true;
                qu.push(make_pair(p,q));
                pr[p][q]=make_pair(d,s);
            }
        }
    }
}

void pathprint(int d, int s)
{
    //printf("..%d %d\n",d,s);
    if(d==-1 && s==-1)
        return;
    else if(!vs[d][s]){
        printf("-1");
        return;
    }
    pathprint(pr[d][s].xx, pr[d][s].yy);
    if(pr[d][s]!=inf) printf("%d",pr[d][s].yy-s);
}

int main()
{
    int d,s;
    scanf("%d %d",&d,&s);
    bfs(d,s);
    pathprint(0,0);
    puts("");
    return 0;
}