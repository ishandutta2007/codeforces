#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev

bool lucky(int a){
        while(a){
                if(a%10!=7&&a%10!=4)
                        return false;
                a/=10;
        }
        return true;
}

const int mod=iinf+7;

int powmod(lng a,int p){
        lng r=1;
        while(p){
                if(p%2){
                        r=r*a%mod;
                        --p;
                }else{
                        a=a*a%mod;
                        p/=2;
                }
        }
        return r;
}

int inv(int a){
        return powmod(a,mod-2);
}

int dp[1100][1100];
int fact[110000];

int C(int n,int k){
        return (lng)fact[n]*inv(fact[k])%mod*inv(fact[n-k])%mod;
}

int main(){
#ifdef __ASD__
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

        //ios_base::sync_with_stdio(false);

        map<int,int> lucks;
        int ucnt=0;
        int n,k;
        cin>>n>>k;
        forn(i,n){
                int a;
                cin>>a;
                if(lucky(a))
                        ++lucks[a];
                else
                        ++ucnt;
        }
        vector<int> szs;
        for(map<int,int>::iterator it=lucks.begin();it!=lucks.end();++it){
                szs.pb(it->second);
        }

        int m=szs.size();
        if(m>=1100)
            exit(9);
        dp[0][0]=1;
        for(int i=1;i<=m;++i){
                dp[i][0]=dp[i-1][0];
                for(int j=1;j<=k&&j<=m;++j){
                        dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*(lng)szs[i-1])%mod;
                }
        }

        fact[0]=1;
        forn(i,100000)
                fact[i+1]=(lng)fact[i]*(i+1)%mod;

        int res=0;
        for(int i=max(0,k-ucnt);i<=k&&i<=m;++i){
                res=(res+dp[m][i]*(lng)C(ucnt,k-i))%mod;
        }

        cout<<res;

        return 0;
}