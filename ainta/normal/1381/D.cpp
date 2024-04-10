#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 251000
using namespace std;
vector<int>E[N_];
int Dep[N_], par[N_][20], Num[N_], Ed[N_], cnt;
int D[N_], D2[N_];
void DFS(int a, int pp){
    par[a][0]=pp;
    Num[a]=++cnt;
    int i;
    for(i=0;i<18;i++)par[a][i+1] = par[par[a][i]][i];
    for(auto &x : E[a]){
        if(x==pp)continue;
        Dep[x]=Dep[a]+1;
        DFS(x,a);
        D[a]=max(D[a],D[x]+1);
    }
    Ed[a]=cnt;
}
bool Include(int a, int b){
    return Num[a]<=Num[b]&&Num[b]<=Ed[a];
}
int Up(int a, int d){
    int i=0;
    while(d){
        if(d&1)a=par[a][i];
        i++;d>>=1;
    }
    return a;
}
int LCA(int a, int b){
    if(Dep[a]<Dep[b])return LCA(b,a);
    a=Up(a,Dep[a]-Dep[b]);
    for(int i=17;i>=0;i--)if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    if(a!=b)a=par[a][0];
    return a;
}
int Lower(int a, int b){
    if(Dep[a]>=Dep[b])return a;
    return b;
}
void DFS2(int a, int pp){
    int M1=0,p1=-1,M2=0,p2=-1;
    M1=D2[a],p1=0;
    for(auto &x : E[a]){
        if(x==pp)continue;
        if(M1<D[x]+1){
            M2=M1,p2=p1;
            M1=D[x]+1,p1=x;
        }
        else if(M2<D[x]+1)M2=D[x]+1,p2=x;
    }
    for(auto &x :E[a]){
        if(x==pp)continue;
        if(p1!=x)D2[x]=M1+1;
        else D2[x]=M2+1;
        DFS2(x,a);
    }
}
void init(int n, vector<int>X, vector<int>Y){
    int i;
    for(i=0;i<=n;i++){
        E[i].clear();
        Dep[i]=0;
        Num[i]=0;
        Ed[i]=0;
        D[i]=D2[i]=0;
    }
    cnt=0;
    for(i=0;i<n-1;i++){
        E[X[i]].push_back(Y[i]);
        E[Y[i]].push_back(X[i]);
    }
    DFS(1,0);
    DFS2(1,0);
}
int Get(vector<int>&V, int l, int m){
    int i;
    int p1=-1,p2=-1;
    int s=0;
    for(i=0;i<=m;i++){
        if(V[i]>=l){
            s+=l-(m-i);
            p1=i;
            break;
        }
    }
    if(p1==0)return s;
    if(p1==-1)return -1;
    for(i=l;i>=m;i--){
        if(V[i]+(m-p1) >= l){
            s+=l - (i-p1);
            p2=i;
            break;
        }
    }
    if(p2==-1)return -1;
    if(p2==l)return s;
    while(1){
        int zz=-1;
        for(i=p1-1;i>=0;i--){
            if(V[i] + (p2-m) >= l)zz=i;
            else break;
        }
        p1 = zz;
        s += l - (p2-p1);
        if(p1==0)return s;
        if(p1==-1)return -1;
        zz = -1;
        for(i=p2+1;i<=l;i++){
            if(V[i] + (m-p1) >= l)zz=i;
            else break;
        }
        p2 = zz;
        s += l - (p2-p1);
        if(p2==l)return s;
        if(p2==-1)return -1;
    }
}
int Calc(int a, int b, int p){
    int l = LCA(a,b), i;
    if(!Include(p,a))swap(a,b);
    int d1 = Dep[a]-Dep[p];
    int d2 = Dep[p]-Dep[l];
    int d3 = Dep[b]-Dep[l];
    vector<int>V, VV;
    int t = a;
    for(i=0;i<d1;i++){
        V.push_back(D[t] + (Dep[t]-Dep[p]));
        t=par[t][0];
    }
    V.push_back(max(D[p],D2[p]));
    t = p;
    for(i=0;i<d2;i++){
        V.push_back(D2[t] + (Dep[p]-Dep[t]));
        t=par[t][0];
    }
    t = b;
    for(i=0;i<d3;i++){
        VV.push_back(D[t] + (Dep[t]-Dep[l]+d2));
        t=par[t][0];
    }
    reverse(VV.begin(),VV.end());
    for(auto &t : VV)V.push_back(t);
    int t1 = Get(V, d1+d2+d3, d1);
    reverse(V.begin(),V.end());
    int t2 = Get(V,d1+d2+d3,d2+d3);
    if(t1==-1&&t2==-1)return -1;
    if(t1==-1)return t2;
    if(t2==-1)return t1;
    return min(t1,t2);
}
int Dist(int a, int b){
    int p = LCA(a,b);
    return Dep[a]+Dep[b]-Dep[p]*2;
}
long long train(vector<int>Z){
    int a = Z[0], b = Z[1];
    int c = Z[2], d = Z[3];
    int p1 = LCA(a,b);
    int p2 = LCA(c,d);
    if(Include(p1,p2))p1 = Lower(LCA(a,p2),LCA(b,p2));
    else if(Include(p2,p1))p2 = Lower(LCA(c,p1),LCA(d,p1));
    int d1 = Calc(a,b,p1);
    int d2 = Calc(c,d,p2);
    if(d1==-1||d2==-1)return -1;
    return d1+d2+Dist(a,b)+Dist(p1,p2);
}
int DD[N_];
void DFS3(int a, int pp, int d){
    DD[a]=d;
    for(auto &x : E[a]){
        if(x==pp)continue;
        DFS3(x,a,d+1);
    }
}
bool Overlap(int a, int p, int b, int q){
    if(!Include(p,q)){
        swap(p,q);
        swap(a,b);
    }
    if(!Include(p,q))return false;
    if(!Include(q,a))return false;
    int tt = LCA(a,b);
    if(tt!=q && Include(q,tt))return true;
    return false;
}
bool Inter(int a, int b, int c, int d){
    int l1 = LCA(a,b);
    int l2 = LCA(c,d);
    if(Overlap(a,l1,c,l2) || Overlap(b,l1,c,l2) || Overlap(a,l1,d,l2)||Overlap(b,l1,d,l2))return true;
    return false;
}
void Solve(){
    int n, A, B, i;
    scanf("%d%d%d",&n,&A,&B);
    vector<int>XX, YY;
    for(i=1;i<n;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        XX.push_back(a);
        YY.push_back(b);
    }
    init(n, XX, YY);
    int d = Dist(A, B);
    for(i=1;i<=n;i++){
        int c=0;
        for(auto &x : E[i]){
            if(par[x][0]!=i)continue;
            if(D[x]+1 >= d)c++;
        }
        if(c>=3 || (c==2 && D2[i]>=d)){
            DFS3(i,0,0);
            for(int j=1;j<=n;j++){
                if(DD[j]==d){
                    if(!Inter(i,j,A,B)){
                        vector<int>ZZ;
                        ZZ.push_back(A);
                        ZZ.push_back(B);
                        ZZ.push_back(i);
                        ZZ.push_back(j);
                        if(train(ZZ)==-1){
                            puts("NO");
                            return;
                        }
                        else{
                            puts("YES");
                            return;
                        }
                    }
                }
            }
    puts("NO");
        }
    }
    puts("NO");
    return;
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}