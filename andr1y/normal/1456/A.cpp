#include <bits/stdc++.h>

using namespace std;

#define DIM 100009
#define INF ((long long)1e18+9ll)
#define pairll pair<long long,long long>
#define fi first
#define se second
#define ld long double
#define MODULO 998244353
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define amen exit(0)
#define endl '\n'

long long i,j,k,l,n,m,res,x,y,p;

long long a[DIM],dp[DIM];

int main(){

    fast;

    int nt;
    cin>>nt;
    while(nt--){
        string s;
        cin>>n>>p>>k>>s>>x>>y;

        for(i=s.length()-1;i>=0;i--){
            dp[i]=(s[i]=='0')*x+(i+k<s.length()?dp[i+k]:0);
        }

        res=INF;

        for(i=p-1;i<s.length();i++){
            res=min(res,(i-p+1)*y+(s[i]=='0')*x+(i+k<s.length()?dp[i+k]:0));
         //   cout<<(i-p+1)<<' '<<(i+)
        }
        cout<<res<<endl;
    }

    amen;
}