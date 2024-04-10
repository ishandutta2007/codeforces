#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

struct seg{
    int l,r;
    int num;
    seg(int c,int R){
        l=c-R;
        r=c+R;
    }
    seg(){};
};

bool cmpsize(const seg& a,const seg& b){
    return a.r-(ll)a.l<b.r-(ll)b.l;
}

bool cmpr(const seg& a,const seg& b){
    if (a.r!=b.r)
        return a.r<b.r;
    return a.l>b.l;     
}

seg a[2100];
seg help[2100];
int helpans[2100];
int helpr[2100];
int anskol[2100];
vector<int> ans;
int ptr;
int t[2100];

pair<int,int> fen[2100];

void init(){
    for (int i=0;i<ptr;i++)
        fen[i]=mp(-1,-1);
}

void add(int pos,const pair<int,int>& val){
    for (;pos<ptr;pos=(pos|(pos+1)))
        fen[pos]=max(fen[pos],val);
}

pair<int,int> get(int r){
    pair<int,int> ans=mp(-1,0);
    for (;r>=0;r=(r&(r+1))-1)
        ans=max(ans,fen[r]);
    return ans;
}

vector<int> g[2100];
int p[2100];

void gen2(int pos,vector<int> & g){
    //cerr<<"!!!!"<<pos<<endl;
    if (pos==-1)
        return;
    g.pb(help[pos].num);
    gen2(p[pos],g);
}


void solve(int i){
    ptr=0;
    for (int j=0;j<i;j++)
        if (a[i].l<=a[j].l && a[j].r<=a[i].r)
            help[ptr++]=a[j];
    if (ptr==0){
        anskol[a[i].num]=1;
        return;
    }

    sort(help,help+ptr,cmpr);
    for (int j=0;j<ptr;j++){
        helpans[j]=anskol[help[j].num];
        helpr[j]=help[j].r;
    }
    memset(t,0,sizeof(t));
    memset(p,-1,sizeof(p));
    init();
    for (int j=0;j<ptr;j++){
        int kol=upper_bound(helpr,helpr+j,help[j].l)-helpr;
        --kol;
        if (kol==-1){
            t[j]=helpans[j];
            p[j]=-1;
        }
        else{
            pair<int,int> tmp=get(kol);
            t[j]=helpans[j]+tmp.first;
            p[j]=tmp.second;
        }
        add(j,mp(t[j],j));
        //if (i==4)
    //      cerr<<help[j].r<<" "<<t[j]<<endl;
    }
    int tmp=get(ptr-1).second;
    gen2(tmp,g[a[i].num]);
    anskol[a[i].num]=t[tmp]+1;
}

int n;

void gen(int v){
//  cerr<<v<<" "<<g[v].size()<<endl;
    ans.pb(v);
    for (int i=0;i<g[v].size();i++){    
        gen(g[v][i]);
    //  cerr<<v<<" "<<g[v][i]<<endl;
    }
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        ::a[i]=seg(a,b);
        ::a[i].num=i;
    }
    n++;
    a[n-1]=seg(0,2000000100);   
    a[n-1].num=n-1;
    sort(a,a+n,cmpsize);
    for (int i=0;i<n;i++)
        solve(i);
    gen(n-1);
    sort(ans.begin(),ans.end());
    cout<<(int)ans.size()-1<<endl;
    for (int i=0;i<ans.size();i++)
        if (ans[i]!=n-1)
            printf("%d ",ans[i]+1);
    printf("\n");
        
    return 0;
}