#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lli = long long;
using pii = pair<lli,int>;

pii arr[200000],brr[200000];
int n,m,mat[200000];
struct seg_tr{
    const static int MAX = 1<<18;
    lli tr[MAX<<1];

    void upd(int cur,int s,int f,int l,int r,lli val) {
        if(f<l || s>r) return;
        else if(l<=s && f<=r) tr[cur] += val;
        else {
            int nx = cur<<1, md=(s+f)>>1;
            upd(nx,s,md,l,r,val);
            upd(nx+1,md+1,f,l,r,val);
        }
    }
    void upd(int l,int r,lli val) {
        if(l > r) return;
        while(r>=m) r-=m, l-=m;
        while(r<0) l+=m, r+=m;
        if(l<0) {
            l += m;
            upd(1,0,MAX-1,l,m-1,val);
            upd(1,0,MAX-1,0,r,val);
        } else {
            upd(1,0,MAX-1,l,r,val);
        }
    }
    void push_all() {
        for(int i=1;i<MAX;i++) {
            int nx = i<<1;
            tr[nx] += tr[i];
            tr[nx+1] += tr[i];
        }
    }
}st;

int lower_idx(pii *arr,lli val) {
    return lower_bound(arr,arr+m, pii(val,0)) - arr;
}
void solve(pii *a, pii *b,int f) {
    for(int i=0;i<m;i++) {
        // a_i - m/2
        int l = 0, r = lower_idx(b, a[i].fi - n/2 + 1) - 1;
        if(f) st.upd(l-i, r-i, n - a[i].fi);
        else st.upd(i-r, i-l, n - a[i].fi);
        
        // a_i
        l = lower_idx(b, a[i].fi - n/2 + 1), r = lower_idx(b, a[i].fi + f) - 1;
        if(f) st.upd(l-i, r-i, a[i].fi);
        else st.upd(i-r, i-l, a[i].fi);
        
        l = lower_idx(b, a[i].fi+f), r = lower_idx(b, a[i].fi + n/2) - 1;
        if(f) st.upd(l-i, r-i, -a[i].fi);
        else st.upd(i-r, i-l, -a[i].fi);

        l = lower_idx(b, a[i].fi + n/2), r = m-1;
        if(f) st.upd(l-i, r-i, a[i].fi);
        else st.upd(i-r, i-l, a[i].fi);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%lld",&arr[i].fi),arr[i].se = i, arr[i].fi--, arr[i].fi *= 2;
    for(int i=0;i<m;i++) scanf("%lld",&brr[i].fi),brr[i].se = i, brr[i].fi--, brr[i].fi *= 2;
    n *= 2;

    sort(arr,arr+m);
    sort(brr,brr+m);

    solve(arr, brr, 1);
    solve(brr, arr, 0);
    
    st.push_all();

    lli ans = 1e18;
    int si = 0;
    for(int i=0;i<m;i++) if(ans > st.tr[i+st.MAX]) {
        ans = st.tr[i+st.MAX];
        si = i;
    }
    
    printf("%lld\n",ans/2);
    for(int i=0;i<m;i++) mat[arr[i].se] = brr[(si+i)%m].se + 1;
    for(int i=0;i<m;i++) printf("%d ",mat[i]);
    
    return 0;
}