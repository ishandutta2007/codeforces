#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=3e5+123,inf=1e9,mod=1e9+7,N=3e5;
int n,X;
vector< pair< pair< int ,int > , pair< int , int > > > v;
int t[4*maxn],val[4*maxn];
map< int ,int > mt1,mt2;
set<int> st;
void upd(int v,int tl,int tr,int l, int r , int k){
    if(l>r)
        return ;
    if(tl==l && tr==r){
        val[v]+=k;
        t[v]+=k;
        return;
    }
    int tm=(tl+tr)/2;
    upd(v+v,tl,tm,l,min(tm,r),k);
    upd(v+v+1,tm+1,tr,max(tm+1,l),r,k);
    t[v]=max(t[v+v],t[v+v+1])+val[v];
}
void get(int v,int tl,int tr,int k){
    if( t[v] + k < n-1)
        return ;
    if( tl==tr ){
        cout<<X<<" "<<mt2[tl]<<endl;
        exit(0);
    }
    int tm=(tl+tr)/2;
    get(v+v,tl,tm,k+val[v]);
    get(v+v+1,tm+1,tr,k+val[v]);    
} 
int main(){    
    scanf("%d",&n);
    for(int i=0;i<n;i++){  
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        v.pb(mp(mp(x1,1),mp(y1,y2)));
        v.pb(mp(mp(x2+1,-1),mp(y1,y2)));
        st.insert(y1);
        st.insert(y2);
    }
    while(!st.empty()){
        int id=mt1.size()+1;
        mt1[*st.begin()]=id;
        mt2[id]=*st.begin();
        st.erase(st.begin());
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();){
        int x=v[i].f.f;
        X=x;
        while(v[i].f.f==x){
            int k=v[i].f.s;
            int l=v[i].s.f,r=v[i].s.s;
            upd(1,1,N,mt1[l],mt1[r],k);
            i++;
        }
        get(1,1,N,0);
    }
    return 0;
}