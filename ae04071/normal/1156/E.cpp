#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;

struct seg_tr{
    static const int MAX=1<<18;
    int tr[MAX<<1];
    void init(int n,int *a) {
        for(int i=0;i<n;i++) tr[MAX+i]=a[i];
        for(int i=MAX-1;i;i--) tr[i]=max(tr[i<<1],tr[i<<1|1]);
    }
    int get(int cur,int s,int f,int l,int r) {
        if(f<l || s>r) return 0;
        else if(l<=s && f<=r) return tr[cur];
        else {
            int nx=cur<<1,md=(s+f)>>1;
            return max(get(nx,s,md,l,r),get(nx+1,md+1,f,l,r));
        }
    }
}st;
int n,arr[200000],pos[200001];

long long ans;
void f(int l,int r) {
    if(l>r) return;
    int mx = st.get(1,0,st.MAX-1,l,r);
    int mi=pos[mx];
    if(r-mi > mi-l) {
        for(int i=l;i<mi;i++) {
            int p=pos[mx-arr[i]];
            if(p>mi && p<=r) ans++;
        } 
    } else {
        for(int i=mi+1;i<=r;i++) {
            int p=pos[mx-arr[i]];
            if(p<mi && p>=l) ans++;
        }
    }
    f(l,mi-1); f(mi+1,r);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i),pos[arr[i]]=i;
    st.init(n,arr);

    f(0,n-1);
    printf("%lld\n",ans);

    return 0;
}