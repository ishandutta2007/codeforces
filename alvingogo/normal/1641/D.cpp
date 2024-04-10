#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

#include<unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W(int n){static char buf[12],p;if(n<0)OB[OP++]='-',n=-n;if(n==0)OB[OP++]='0';p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];write(1,OB,OP);}
 
int main(){
    AquA;
    int n=R(),m=R();
    //cin >> n >> m;
    vector<pair<int,vector<int> > > v(n,{0,vector<int>(m)});
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i].sc[j]=R();
        }
        v[i].fs=R();
        sort(v[i].sc.begin(),v[i].sc.end());
    }
    sort(v.begin(),v.end(),[&](pair<int,vector<int> > a,pair<int,vector<int> > b){return a.fs<b.fs;});
    //map<long long,int> p;
    const int inf=1e9;
    int ans=inf+inf+7;
    const int mod[2]={inf+7,inf+9};
    const int bs[2]={inf+4,inf+1};
    auto hash=[&](vector<int>& a){
        pair<long long,long long> b;
        for(auto h:a){
            b.fs*=bs[0];
            b.sc*=bs[1];
            b.fs+=h;
            b.sc+=h;
            b.fs%=mod[0];
            b.sc%=mod[1];
        }
        return b.fs*(inf+inf)+b.sc;
    };
    vector<vector<long long> > hs(n,vector<long long>(1<<m));
    vector<int> cc(1<<m);
    vector<int> p(n*(1<<m));
    vector<long long> gg;
    for(int j=0;j<(1<<m);j++){
        cc[j]=__builtin_popcount(j)%2?1:-1;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<(1<<m);j++){ 
            vector<int> y;
            for(int k=0;k<m;k++){
                if((j>>k)&1){
                    y.push_back(v[i].sc[k]);
                }
            }
            hs[i][j]=hash(y);
            gg.push_back(hs[i][j]);
        }
    }
    sort(gg.begin(),gg.end());
    gg.erase(unique(gg.begin(),gg.end()),gg.end());
    for(auto &h:hs){
        for(auto &q:h){
            q=lower_bound(gg.begin(),gg.end(),q)-gg.begin();
        }
    }
    auto add=[&](int i,int x){
        for(int j=1;j<(1<<m);j++){
            p[hs[i][j]]+=x*cc[j];
        }
    };
    auto query=[&](int i){
        int re=0;
        for(int j=1;j<(1<<m);j++){
            re+=p[hs[i][j]];
        }
        return re;
    };
    int l=0,r=n-1;
    for(int i=0;i<n;i++){
        add(i,1);
    }
    while(l<n && l<=r){
        while(r>=l && v[r].fs+v[l].fs>=ans){
            add(r,-1);
            r--;
        }
        while(r>=l && query(l)!=r+1){
            add(r,-1);
            r--;
        }
        if(l>r){
            break;
        }
        if(r!=n-1){
            ans=min(ans,v[r+1].fs+v[l].fs);
        }
        l++;
    }
    if(ans==inf+inf+7){
        W(-1);
        //cout << -1 << "\n";
    }
    else{
        W(ans);
        //cout << ans << "\n";
    }
    return 0;
}