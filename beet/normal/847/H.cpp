#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
int A[111111];

int L[111111],lv[111111];
int R[111111],rv[111111];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];

    L[0]=0;
    lv[0]=A[0];
    for(int i=1;i<N;i++){
        if(lv[i-1]<A[i]){
            lv[i]=A[i];
            L[i]=L[i-1];
        }
        else{
            lv[i]=lv[i-1]+1;
            L[i]=L[i-1]+lv[i]-A[i];
        }
    }

    R[N-1]=0;
    rv[N-1]=A[N-1];
    for(int i=N-2;i>=0;i--){
        if(rv[i+1]<A[i]){
            rv[i]=A[i];
            R[i]=R[i+1];
        }
        else{
            rv[i]=rv[i+1]+1;
            R[i]=R[i+1]+rv[i]-A[i];
        }
    }

    int ans=LLONG_MAX;
    rep(i,N){
        int cost=L[i]+R[i]-(lv[i]-A[i])-(rv[i]-A[i]);
        cost+=max(lv[i],rv[i])-A[i];
        chmin(ans,cost);
    }
    cout<<ans<<endl;
    return 0;
}