#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;

const int ADD=5001,MAX=10001;
int tr[MAX+1];
void upd(int cur,int v) {
    while(cur<=MAX) {
        tr[cur]+=v;
        cur+=cur&-cur;
    }
}
int get(int cur) {
    int ret=0;
    while(cur) {
        ret+=tr[cur]; cur-=cur&-cur;
    }
    return ret;
}
int sum(int l,int r) {
    return get(r)-get(l-1);
}

int n;
vector<pair<int,pii>> hor,ver;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a>c) swap(a,c);
        if(b>d) swap(b,d);
        a+=ADD; b+=ADD; c+=ADD; d+=ADD;
        if(a==c) ver.push_back({a,pii(b,d)});
        else hor.push_back({b,pii(a,c)});
    }
    sort(hor.begin(),hor.end());
    sort(ver.begin(),ver.end());

    long long ans=0;
    for(int i=0;i<sz(ver);i++) {
        vector<pii> arr;
        for(auto &v:hor) if(ver[i].se.fi<=v.fi && v.fi<=ver[i].se.se &&
                v.se.fi<=ver[i].fi && ver[i].fi <= v.se.se) {
            upd(v.fi,1);
            arr.push_back({v.se.se,v.fi});
        }
        int k=0;
        sort(arr.begin(),arr.end());
        for(int j=i+1;j<sz(ver);j++) {
            while(k<sz(arr) && ver[j].fi > arr[k].fi) {
                upd(arr[k++].se, -1);
            }
            int mn=max(ver[i].se.fi, ver[j].se.fi), mx = min(ver[i].se.se, ver[j].se.se);
            if(mn>=mx) continue;
            
            int cnt = sum(mn, mx);
            ans += 1ll*cnt*(cnt-1)/2;
        }
        while(k<sz(arr)) {
            upd(arr[k++].se, -1);
        }
    }
    printf("%lld\n",ans);

    return 0;
}