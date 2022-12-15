#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;

int n,m,a[200001];

vector<int> make_base(vector<int> a,vector<int> b) {
    vector<int> res(sz(a) + sz(b));
    for(int i=0;i<sz(a);i++) res[i] = a[i];
    for(int i=0;i<sz(b);i++) res[i+sz(a)] = b[i];

    int cnt=0;
    for(int i=0;i<30;i++) {
        for(int j=cnt;j<sz(res);j++) if(res[j]>>i&1) {
            swap(res[cnt],res[j]);
            for(int k=j+1;k<sz(res);k++) if(res[k]>>i&1) res[k] ^= res[cnt];
            cnt++;
            break;
        }
    }
    res.resize(cnt);
    return res;
}
struct seg_tr{
    const static int MAXN = 1<<18;
    int tr[MAXN<<1];
    vector<int> basis[MAXN<<1];
    void upd(int cur,int val) {
        tr[cur+=MAXN] ^= val;
        basis[cur] = vector<int>(1,tr[cur]);
        cur>>=1;
        while(cur) {
            tr[cur] ^= val;
            basis[cur] = make_base(basis[cur<<1], basis[cur<<1|1]);
            cur>>=1;
        }
    }
    int sum(int l,int r) {
        int res=0;
        l+=MAXN; r+=MAXN;
        while(l<=r) {
            if(l&1) res^=tr[l++];
            if(!(r&1)) res^=tr[r--];
            l>>=1; r>>=1;
        }
        return res;
    }
    vector<int> getBasis(int l,int r) {
        vector<int> res;
        l+=MAXN; r+=MAXN;
        while(l<=r) {
            if(l&1) res = make_base(res, basis[l++]);
            if(!(r&1)) res = make_base(res, basis[r--]);
            l>>=1; r>>=1;
        }
        return res;
    }
}tr;

long long pw[31];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) tr.upd(i,a[i]^a[i-1]);

    pw[0]=1;
    for(int i=1;i<=30;i++) pw[i] = pw[i-1]*2;
    
    while(m--) {
        int t,a,b,v;
        scanf("%d%d%d",&t,&a,&b);
        if(t==1) {
            scanf("%d",&v);
            tr.upd(a,v);
            tr.upd(b+1,v);
        } else {
            vector<int> lb(1, tr.sum(1,a));
            vector<int> rb = tr.getBasis(a+1,b);
            printf("%lld\n",pw[sz(make_base(lb,rb))]);
        }
    }
    
    return 0;
}