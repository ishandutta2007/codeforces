#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//#define int ll
 
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

ll rand_int(ll l, ll r) { //[l, r]
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}

#define N_ 251000

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        int n, K, m;
        scanf("%d%d",&n,&K);
        vc<ll> A(n+1), CA(n+1);
        rng(i,1,n){
            scanf("%lld",&A[i]);
            CA[i] = 1;
            while(A[i]%K==0){
                A[i]/=K;
                CA[i]*=K;
            }
        }
        scanf("%d",&m);
        vc<ll> B(m+1), CB(m+1);
        rng(i,1,m){
            scanf("%lld",&B[i]);
            CB[i] = 1;
            while(B[i]%K==0){
                B[i]/=K;
                CB[i]*=K;
            }
        }
        int p1 = 1, p2 = 1, ck = 0;
        while(p1 <= n || p2 <= m){
            if(p1<=n && !CA[p1]){
                p1++;
                continue;
            }
            if(p2<=m && !CB[p2]){
                p1++;
                continue;
            }
            if(p1 > n || p2 > m){
                ck=1;
                break;
            }
            if(A[p1] != B[p2]){
                ck=1;
                break;
            }
            if(CA[p1] < CB[p2]){
                CB[p2] -= CA[p1];
                p1++;
            }
            else{
                CA[p1] -= CB[p2];
                p2++;
            }
        }
        if(!ck)puts("Yes");
        else puts("No");
    }
}