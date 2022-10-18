#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif
 
const int INF=1e9+7;
int arr[100005],bit[100005],ans[300005];
vector<int> v,st,st2;
vector<pii> qry[100005];
int n,seg[400005],pl[100005];
 
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
        return seg[rt];
    int m=l+r>>1;
    if(R<=m) return query(L,R,l,m,rt<<1);
    if(L>m) return query(L,R,m+1,r,rt<<1|1);
    return max(query(L,R,l,m,rt<<1),query(L,R,m+1,r,rt<<1|1));
}
 
void modify(int x,int l,int r,int rt,int val)
{
    if(l==r)
        return seg[rt]=val,void();
    int m=l+r>>1;
    if(x<=m) modify(x,l,m,rt<<1,val);
    else modify(x,m+1,r,rt<<1|1,val);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}
 
int bquery(int x)
{
    int rt=INF;
    for(;x<=n;x+=x&-x)
        rt=min(rt,bit[x]);
    return rt;
}
 
void bmodify(int x,int val)
{
    for(;x;x-=x&-x)
        bit[x]=min(bit[x],val);
}
 
int main()
{
    IOS();
    int q,l,r;
    cin >> n;
    for(int i=1;i<=n;++i)
        cin >> arr[i],v.pb(arr[i]),bit[i]=INF;
    sort(ALL(v)),v.resize(unique(ALL(v))-v.begin());
    for(int i=1;i<=n;++i)
        pl[i]=upper_bound(ALL(v),arr[i])-v.begin();
    cin >> q;
    for(int i=1;i<=q;++i)
        cin >> l >> r,qry[r].pb(pii(l,i));
    st.pb(1),st2.pb(1),modify(pl[1],1,SZ(v),1,1);
    for(int i=2;i<=n;++i)
    {
        while(!st.empty()&&arr[i]<arr[st.back()])
            st.pop_back();
        if(!st.empty())
        {
            bmodify(st.back(),arr[i]-arr[st.back()]),l=pl[st.back()];
            while(l<pl[i])
            {
                int p=query(l+1,pl[i],1,SZ(v),1);
                if(!p) break;
                if(arr[i]-arr[p]<=arr[p]-v[l-1])
                    bmodify(p,arr[i]-arr[p]),l=pl[p];
                else
                {
                    l=upper_bound(ALL(v),arr[i]-(arr[p]-v[l-1]))-v.begin()+1;
                    if(l>pl[i]) break;
                    p=query(l,pl[i],1,SZ(v),1);
                    if(!p) break;
                    bmodify(p,arr[i]-arr[p]),l=pl[p];
                }
            }
        }
        st.pb(i);
        
        while(!st2.empty()&&arr[i]>arr[st2.back()])
            st2.pop_back();
        if(!st2.empty())
        {
            bmodify(st2.back(),arr[st2.back()]-arr[i]),r=pl[st2.back()];
            while(pl[i]<r)
            {
                int p=query(pl[i],r-1,1,SZ(v),1);
                if(!p) break;
                if(arr[p]-arr[i]<=v[r-1]-arr[p])
                    bmodify(p,arr[p]-arr[i]),r=pl[p];
                else
                {
                    r=lower_bound(ALL(v),arr[i]+(v[r-1]-arr[p]))-v.begin();
                    if(pl[i]>r) break;
                    p=query(pl[i],r,1,SZ(v),1);
                    if(!p) break;
                    bmodify(p,arr[p]-arr[i]),r=pl[p];
                }
            }
        }
        st2.pb(i);
        
        modify(pl[i],1,SZ(v),1,i);
        for(pii j:qry[i])
            ans[j.Y]=bquery(j.X);
    }
    for(int i=1;i<=q;++i)
        cout << ans[i] << "\n";
}