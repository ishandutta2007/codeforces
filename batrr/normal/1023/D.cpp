#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;

int n,q,x,t[4*maxn],a[maxn];
vector<int> v[maxn];
set< int > st;
void up(int v,int tl, int tr,int pos){
    if(tl==tr){
        t[v]++;
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm)            
        up(v+v,tl,tm,pos);
    else
        up(v+v+1,tm+1,tr,pos);
    t[v]++;
}
int get(int v,int tl, int tr,int l, int r){
    if(l>r)
        return 0;
    if(tl==l && tr==r)
        return t[v];
    int tm=(tl+tr)/2;
    return get(v+v,tl,tm,l,min(tm,r)) + get(v+v+1,tm+1,tr,max(tm+1,l),r);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x==0){
            st.insert(i);
        }else{
            v[x].pb(i);
        }
        a[i]=x;
    }
    st.insert(1e9);
    for(int i=q;i>=1;i--){
        
        if( v[i].empty() ){
            if(i==q){
                if( st.size()==1 ){
                    puts("NO");
                    return 0;
                }
                v[i].pb(*st.begin());
                a[*st.begin()]=i;
                st.erase(st.begin());
            }else
                continue;
        }
        
        int l=v[i][0],r=v[i].back();
        while(!st.empty() && *st.lower_bound(l)<=r ){
            a[*st.lower_bound(l)]=i;
            v[i].pb(*st.lower_bound(l));
            st.erase(st.lower_bound(l));
        }
        for( auto x:v[i] )
            up(1,1,n,x);
        if( get(1,1,n,l,r)!=r-l+1 ){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++){
        if(a[i]==0)
            a[i]=1;
        printf("%d ",a[i]);
    }
}