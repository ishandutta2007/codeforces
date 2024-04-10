#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;

struct vec{
    lli x,y;
    vec() {}
    vec(lli x,lli y):x(x),y(y) {}
    vec operator-(const vec &rhs)const {
        return vec(x-rhs.x,y-rhs.y);
    }
    lli cross(const vec &rhs)const {
        return x*rhs.y - y*rhs.x;
    }
};
int ccw(vec a,vec b) {
    lli ret=a.cross(b);
    if(ret>0) return 1;
    else if(ret==0) return 0;
    else return -1;
}
int ccw(vec p,vec a,vec b) {
    return ccw(a-p,b-p);
}
bool cmp_pos(const vec &a,const vec &b) {
    return a.x!=b.x ? a.x<b.x : a.y<b.y;
}

lli dp[301][301][4];

vector<int> get_idx(vector<pair<vec,int>> &arr,vec p) {
    sort(arr.begin(),arr.end(),[&](const pair<vec,int> &a,const pair<vec,int> &b) {
        return ccw(p,a.fi,b.fi)>0;
    });
    vector<int> ret(sz(arr),0);
    for(int i=0;i<sz(arr);i++) ret[i] = arr[i].se;
    return ret;
}
lli solve(vector<vec> arr) {
    memset(dp,0,sizeof(dp));
    function<bool(const vec&, const vec&)> cmp_angle = [&](const vec &a,const vec &b) {
        return ccw(arr[0],a,b)>0;
    };
    sort(arr.begin()+1,arr.end(),cmp_angle);

    int n=sz(arr);
    vector<vector<int>> pr(n,vector<int>()),nx(n,vector<int>());
    for(int i=1;i<n;i++) {
        vector<pair<vec,int>> ta;
        for(int j=0;j<i;j++) ta.push_back({arr[j],j});
        pr[i] = get_idx(ta,arr[i]);
        ta.clear();
        for(int j=i+1;j<n;j++) ta.push_back({arr[j],j});
        nx[i] = get_idx(ta,arr[i]);
    }
    
    for(int i=1;i<n;i++) dp[i][0][0]=1;
    for(int t=1;t<4;t++) {
        for(int i=1;i<n;i++) {
            lli ps=0;
            int pi=0;
            for(int ni=0;ni<sz(nx[i]);ni++) {
                while(pi < sz(pr[i]) && ccw(arr[i],arr[nx[i][ni]],arr[pr[i][pi]])>0) {
                    ps += dp[i][pr[i][pi++]][t-1];
                }
                dp[nx[i][ni]][i][t] = ps;
            }
        }
    }
    
    lli ret=0;
    for(int i=1;i<n;i++)for(int j=1;j<i;j++) if(ccw(arr[i],arr[0],arr[j])>0){
        ret += dp[i][j][3];
    }
    return ret;
}

int main() {
    vector<vec> arr;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        lli x,y;
        scanf("%lld%lld",&x,&y);
        arr.push_back(vec(x,y));
    }
    sort(arr.begin(),arr.end(),cmp_pos);
    
    lli ans=0;
    for(int i=0;i<=n-5;i++) {
        vector<vec> tmp;
        for(int j=i;j<n;j++) tmp.push_back(arr[j]);
        ans += solve(tmp);
    }
    printf("%lld\n",ans);
    
    return 0;
}