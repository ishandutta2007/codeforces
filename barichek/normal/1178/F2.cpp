#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
 
using namespace std;
///#define int long long
 
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
 
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
 
///---program start---///
 
#define md (ll)(998244353ll)
 
#define ar (int)(500+10)
 
int a[1000000+10];
 
int a1[ar];
int a2[ar];
 
bool edge[ar][ar];
bool new_edge[ar][ar];
 
vi reb[ar];
 
vector<vector<int>> dp[ar];
 
int min_in_subtree[ar];
 
int get_dp(int val,int l,int r)
{
    if (l>r){
        return 1;
    }
    if (reb[val].empty()){
        return 1;
    }
    if (dp[val][l][r]!=-1){
        return dp[val][l][r];
    }
    int res=0;
 
    int pos=l;
    for (int i=l;i<=r;i++){
        if (reb[val][i]<reb[val][pos]){
            pos=i;
        }
    }
 
    int sum1=0;
    for (int k=pos;k>=l;k--){
        if (k<=pos-1&&a2[reb[val][k]]!=a1[reb[val][k+1]]-1){
            break;
        }
        sum1+=1ll*get_dp(val,l,k-1)*get_dp(val,k,pos-1)%md;
        if (sum1>=md){
            sum1-=md;
        }
    }
 
    int sum2=0;
    for (int k=pos;k<=r;k++){
        if (k>=pos+1&&a1[reb[val][k]]!=a2[reb[val][k-1]]+1){
            break;
        }
        sum2+=1ll*get_dp(val,pos+1,k)*get_dp(val,k+1,r)%md;
        if (sum2>=md){
            sum2-=md;
        }
    }
 
    dp[val][l][r]=1ll*sum1*sum2%md*
                get_dp(reb[val][pos],0,len(reb[reb[val][pos]])-1)%md;
 
//    cout<<"("<<sum1<<" "<<sum2<<")"<<"\n";
//    cout<<"dp["<<val<<"]["<<l<<"]["<<r<<"] :: "<<dp[val][l][r]<<"\n";
 
    return dp[val][l][r];
}
 
bool in(int a,int l,int r)
{
    return l<=a&&a<=r;
}
 
bool in(int l1,int r1,int l2,int r2)
{
    return in(l1,l2,r2)&&in(r1,l2,r2);
}
 
int intersect(int l1,int r1,int l2,int r2)
{
    return max(0,min(r1,r2)-max(l1,l2)+1);
}
 
main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
 
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>a[i];
        a2[a[i]]=i;
    }
    for (int i=m;i>=1;i--){
        a1[a[i]]=i;
    }
    for (int i=1;i<=n;i++){
        if (*min_element(a+a1[i],a+a2[i]+1)<i){
            cout<<0<<"\n";
            return 0;
        }
    }
    a1[0]=0;
    a2[0]=m+1;
 
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            if (i!=j){
                if (in(a1[j],a2[j],a1[i],a2[i])){
                    edge[i][j]=1;
                    new_edge[i][j]=1;
                    if (j<i){
//                        cout<<"barik lol 1"<<"\n";
                        cout<<0<<"\n";
                        return 0;
                    }
                }
                else if (!in(a1[i],a2[i],a1[j],a2[j])
                         &&intersect(a1[j],a2[j],a1[i],a2[i])!=0){
//                        cout<<"barik lol 2"<<" :: "<<i<<" "<<j<<"\n";
                        cout<<0<<"\n";
                        return 0;
                }
            }
        }
    }
 
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            for (int k=0;k<=n;k++){
                if (edge[i][j]&&edge[j][k]){
                    new_edge[i][k]=0;
                }
            }
        }
    }
 
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            if (new_edge[i][j]){
                reb[i].pb(j);
//                cout<<"reb :: "<<i<<" "<<j<<"\n";
            }
        }
    }
 
    for (int i=0;i<=n;i++){
        dp[i].assign(reb[i].size(),vector<int>(reb[i].size(),-1));
        sort(all(reb[i]),[&](int l1,int l2){
             return a1[l1]<a1[l2];
             }
             );
//        cout<<"reb["<<i<<"] :: ";
//        for (auto j:reb[i]){
//            cout<<j<<" ";
//        }
//        cout<<"\n";
    }
 
    cout<<get_dp(0,0,len(reb[0])-1)<<"\n";
}