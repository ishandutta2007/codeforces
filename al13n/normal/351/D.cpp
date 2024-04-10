#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define clr(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define forv(i,v) forn(i,sz(v))
typedef pair<int,int> PII;
typedef long long lng;
const int INF=1000000000;
const lng LINF=1LL*INF*INF;

int tree[410000];
int tree2[410000];

void setv(int p,int v1,int v2,int a,int b,int k){
    if(b==a+1){
        tree[k]=v1;
        tree2[k]=v2;
        return;
    }
    int c=(a+b)/2;
    if(p<c)
        setv(p,v1,v2,a,c,k*2+1);
    else
        setv(p,v1,v2,c,b,k*2+2);
    tree[k]=tree[k*2+1]+tree[k*2+2];
    tree2[k]=max(tree2[k*2+1],tree2[k*2+2]);
}
int getsum(int l,int r,int a,int b,int k){
    if(l<=a && r>=b)
        return tree[k];
    if(r<=a || l>=b)
        return 0;
    int c=(a+b)/2;
    return getsum(l,r,a,c,k*2+1)+getsum(l,r,c,b,k*2+2);
}
int getmax(int l,int r,int a,int b,int k){
    if(l<=a && r>=b)
        return tree2[k];
    if(r<=a || l>=b)
        return -1;
    int c=(a+b)/2;
    return max(getmax(l,r,a,c,k*2+1),getmax(l,r,c,b,k*2+2));
}

int n;
int A[110000];
int res[110000];
vector<PII> qus[110000];
int R[110000];
vector<int> pos[110000];

int main()
{
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    cin>>n;
    forn(i,n){
        scanf("%d",A+i);
        pos[A[i]].pb(i);
    }
    int q;
    cin>>q;
    forn(i,q){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;
        qus[a].pb(mp(b,i));
    }

    clr(R,-1);
    forn(c,100010){
        vector<int> &p=pos[c];
        if(!sz(p))
            continue;
        int a=0;
        while(true){
            int d=(a+1<sz(p))?p[a+1]-p[a]:0;
            int b=a;
            while(b+1<sz(p) && p[b+1]-p[b]==d)
                ++b;
            int y=(b+1<sz(p))?p[b+1]:n;
            for(int i=a;i<=b;++i){
                R[p[i]]=max(R[p[i]],y);
            }
            if(a==b)
                break;
            a=b;
        }
        reverse(all(p));
        setv(p.back(),1,R[p.back()],0,n,0);
        p.pop_back();
    }
    forn(i,n){
        forv(j,qus[i]){
            int b=qus[i][j].X;
            int t1=getsum(i,b,0,n,0);
            int tt=getmax(i,b,0,n,0);
            int t2=b<=tt?0:1;
            res[qus[i][j].Y]=t1+t2;
        }
        if(sz(pos[A[i]])){
            setv(pos[A[i]].back(),1,R[pos[A[i]].back()],0,n,0);
            pos[A[i]].pop_back();
        }
    }
    forn(i,q){
        printf("%d\n",res[i]);
    }

    return 0;
}