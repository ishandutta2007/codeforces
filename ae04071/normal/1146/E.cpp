#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,q;
struct seg_tr{
    static const int MAX = 1<<17;
    int tr[MAX<<1];
    void init(int n,vector<pii> &arr) {
        for(int i=0;i<n;i++) {
            if(arr[i].first < 0) tr[i+MAX]=2;
            else tr[i+MAX] = 1;
        }
    }
    void push(int cur) {
        if(!tr[cur] || cur >= MAX) return;

        int nx=cur<<1;
        if(tr[cur]==3) {
            tr[nx]^=tr[cur];
            tr[nx+1]^=tr[cur];
        } else {
            tr[nx] = tr[nx+1] = tr[cur];
        }
        tr[cur]=0;
    }
    void upd(int cur,int s,int f,int l,int r,int v) {
        push(cur);
        if(f<l || s>r) return;
        else if(l<=s && f<=r){
            if(cur>=MAX && v==3) tr[cur]^=v;
            else tr[cur]=v;
            push(cur);
        } else {
            int nx=cur<<1,md=(s+f)>>1;
            upd(nx,s,md,l,r,v);
            upd(nx+1,md+1,f,l,r,v);
        }
    }
    void upd(int l,int r,int v) {
        if(l>r) return;
        upd(1,0,MAX-1,l,r,v);
    }
    void push_all() {
        for(int i=1;i<MAX;i++) {
            push(i);
        }
    }
}st;

int ans[100000];
inline int _abs(int a) {return a<0 ? -a : a;}
int main() {
    vector<pii> arr;
    scanf("%d%d",&n,&q);
    for(int i=0,v;i<n;i++) scanf("%d",&v),arr.push_back(pii(v,i));
    sort(arr.begin(),arr.end(),[](const pii &a,const pii &b) {
            return _abs(a.first) < _abs(b.first);
            });

    st.init(n,arr);
    for(int i=0;i<n;i++) arr[i].first = _abs(arr[i].first);

    while(q--) {
        char ch;
        int x,l;
        scanf(" %c %d",&ch,&x);
        if(ch=='>') {
            if(x>=0)  {
                l = upper_bound(arr.begin(),arr.end(),pii(_abs(x),n))-arr.begin();
                st.upd(l,n-1,2);
            } else {
                l = upper_bound(arr.begin(),arr.end(),pii(_abs(x),-1))-arr.begin();
                st.upd(0,l-1,3);
                st.upd(l,n-1,2);
            }
        } else {
            if(x<=0) {
                l = upper_bound(arr.begin(),arr.end(),pii(_abs(x),n))-arr.begin();
                st.upd(l,n-1,1);
            } else {
                l = upper_bound(arr.begin(),arr.end(),pii(_abs(x),-1))-arr.begin();
                st.upd(0,l-1,3);
                st.upd(l,n-1,1);
            }
        }
    }
    st.push_all();
    for(int i=0;i<n;i++) {
        if(st.tr[st.MAX+i]==1) ans[arr[i].second] = arr[i].first;
        else ans[arr[i].second]=-arr[i].first;
    }
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    puts("");

    return 0;
}