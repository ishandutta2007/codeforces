#include<cstdio>
#include<algorithm>
#include<random>
#include<ctime>
#include<map>
#include<vector>
#define SZ 262144
#define pii pair<int,int>
using namespace std;
int n, Bef[201000];
long long w[201000];
map<pii,int>Map[201000];
struct Tree{
    int K[SZ+SZ], T[SZ+SZ];
    void init(){
        for(int i=0;i<SZ+SZ;i++)K[i]=-1;
    }
    void Put2(int nd, int x){
        K[nd]=T[nd]=x;
    }
    void UDT(int nd){
        T[nd]=(T[nd*2]|T[nd*2+1]);
    }
    void Spread(int nd){
        if(K[nd]!=-1){
            Put2(nd*2,K[nd]);
            Put2(nd*2+1,K[nd]);
        }
        K[nd]=-1;
    }
    void Put(int nd, int b, int e, int s, int l, int x){
        if(s>l)return;
        if(s<=b&&e<=l){
            Put2(nd,x);
            return;
        }
        Spread(nd);
        int m = (b+e)>>1;
        if(s<=m)Put(nd*2,b,m,s,l,x);
        if(l>m)Put(nd*2+1,m+1,e,s,l,x);
        UDT(nd);
    }
    int Left(int nd, int b, int e, int s, int l){
        if(!T[nd])return l+1;
        if(s>l)return l+1;
        if(b==e)return b;
        Spread(nd);
        int m = (b+e)>>1;
        if(s<=m){
            int x = Left(nd*2,b,m,s,l);
            if(x<=l)return x;
        }
        if(l>m){
            return Left(nd*2+1,m+1,e,s,l);
        }
        return l+1;
    }
}IT;
struct Range{
    int b, e;
};
vector<Range>Save;

long long Sum1(int b, int e){
    return 1ll*((n-b+1) + (n-e+1))*(e-b+1)/2;
}

void Calc(int b, long long x, int e, long long y){
    int i;
    for(i=0;i<=e-b-1;i++){
        long long t2 = Sum1(b+1,b+i) + x;
        long long t1 = Sum1(e-i,e-1) + x;
        long long tp = n-e+1;
        if(t1 + tp<= y && y <= t2+tp){
            Map[e][{e,e}] = b;
            Save.push_back({e,e});
        }
        long long bbb = n+1+t1-y+1;
        long long eee = n+1+t2-y+1;
        bbb=max(bbb,(long long)e+1);
        eee=min(eee,(long long)n+1);
        if(bbb<=eee){
            int b1=bbb,e1=eee;
            Map[e][{b1,e1}] = b;
            Save.push_back({b1,e1});
        }
    }
}

void Do(int b, int e){
    //printf("%d %d\n",b,e);
    Save.clear();
    if(IT.Left(1, 0, n+1, b, b) == b){
        Calc(b, w[b], e, w[e]);
    }
    int pp = IT.Left(1, 0, n+1, b+1, e-1);
    if(b+1<=pp&&pp<=e-1){
        Calc(pp, w[b]-1, e, w[e]);
    }
    if(IT.Left(1, 0, n+1, e, e) == e && w[e]!=w[b]-1){
        IT.Put(1, 0, n+1, e, e, 0);
    }
    if(w[b]!=w[e]){
        IT.Put(1, 0, n+1, e+1, n+1, 0);
    }
    IT.Put(1, 0, n+1, 0, e-1, 0);
    for(auto &t : Save){
        IT.Put(1, 0, n+1, t.b, t.e, 1);
    }
}
int Res[201000];
void Print2(long long b, long long e, int c, long long s){
    if(c==0)return;
    long long t2 = Sum1(b+1, b+c-1);
    long long t1 = Sum1(e-c+2,e);
    if(t1 <= s-(n-b+1) && s-(n-b+1) <= t2){
        Res[b]=1;
        Print2(b+1,e,c-1,s-(n-b+1));
    }
    else{
        Print2(b+1,e,c,s);
    }
}
void Print(int ty, long long s1, int x, int y, long long s2){
    Res[ty]=Res[y]=1;
    
    long long ss = s2 - (n-y+1) - s1;
    int i;
    
    
    for(i=0;i<=x-ty-1;i++){
        long long t2 = Sum1(ty+1, ty+i);
        long long t1 = Sum1(x-i,x-1);
        if(t1<=ss && ss<=t2){
            Print2(ty+1,x-1,i,ss);
            return;
        }
    }
}
int RR[101000];
long long Res2[101000];
int main(){
    int i, DEB = 0;
    scanf("%d",&n);

    mt19937 rng((unsigned)time(NULL));
    if(DEB){
    long long ss=0;
    for(i=1;i<=n+1;i++){
        RR[i]=!!(rng()%5);
        if(i==n+1)RR[i]=1;
        if(RR[i]){
            ss+=(n-i+1);
            Res2[i]=ss;
        }
    }
    for(i=1;i<=n;i++)printf("%d",RR[i]);
    puts("");
    long long z=Res2[n+1];
    for(i=n;i>=1;i--){
        if(Res2[i])z=Res2[i];
        else Res2[i]=z+1;
    }
    }
    int ck=0;
    for(i=1;i<=n;i++){
        if(!DEB){
        scanf("%lld",&w[i]);
        }
        if(DEB){
        if(rng()%3==0){
            w[i]=Res2[i];
        }
        printf("%lld ",w[i]);
        }
        if(w[i]!=0 && w[i]!=1)ck=1;
    }
    if(!ck){
        for(i=1;i<=n;i++)printf("0");
        puts("");
        return 0;
    }
    IT.Put(1, 0, n+1, 0, 0, 1);
    int prv = 0;
    for(i=1;i<=n;i++){
        if(!w[i])continue;
        Do(prv,i);
        Bef[i]=prv;
        prv=i;
    }
    int x = prv, y = IT.Left(1,0,n+1,0,n+1);
    while(x){
        for(auto &t : Map[x]){
            pii tp = t.first;
            if(tp.first<=y && y<=tp.second){
                int ty = t.second;
                long long s1 = w[Bef[x]], s2 = w[x];
                if(ty != Bef[x]){
                    s1--;
                }
                if(y != x){
                    s2--;
                }
                Print(ty, s1, x, y, s2);
                
                y = ty;
                break;
            }
        }
        x = Bef[x];
    }
    for(i=1;i<=n;i++)printf("%d",Res[i]);
    puts("");
}