#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=998244353; //1000000007;




int main(){
    ll n,k,len;
    cin>>n>>k>>len;
    if(len==1){
        cout<<0<<endl;
        return 0;
    }
    vector<ll> a(n);
    for(auto &i:a){
        cin>>i;
        if(i>0){i--;}
    }
    vector<vector<ll>> dp(n,vector<ll>(k,0));
    vector<ll> sum(n,0);
    if(a[0]==-1){
        for(int i=0;i<k;i++){dp[0][i]=1;}
        sum[0]=k;
    }
    else{dp[0][a[0]]=1; sum[0]=1;}
    vector<vector<ll>> count(n,vector<ll>(k,0));
    if(a[0]==-1){
        for(int i=0;i<k;i++){
            count[0][i]++;
        }
    }
    else{count[0][a[0]]++;}
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            count[i][j]=count[i-1][j];
            if(a[i]==-1){count[i][j]++;}
        }
        if(a[i]>=0){count[i][a[i]]++;}
        if(i-len>=0){
            if(a[i-len]==-1){
                for(int j=0;j<k;j++){
                    count[i][j]--;
                }
            }
            else{
                count[i][a[i-len]]--;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]==-1){
            for(int j=0;j<k;j++){
                dp[i][j]=sum[i-1];
                if(i-len+1>=0 && count[i][j]==len){
                    if(i-len+1==0){dp[i][j]--;}
                    else{dp[i][j]-=sum[i-len]-dp[i-len][j];}
                }
            }
        }
        else{
            dp[i][a[i]]=sum[i-1];
            if(i-len+1>=0 && count[i][a[i]]==len){
                if(i-len+1==0){dp[i][a[i]]--;}
                else{dp[i][a[i]]-=sum[i-len]-dp[i-len][a[i]];}
            }
        }
        for(int j=0;j<k;j++){
            dp[i][j]%=MOD;
            sum[i]+=dp[i][j];
            sum[i]%=MOD;
        }
    }
    if(sum.back()<0){sum.back()+=MOD;}
    cout<<sum.back()<<endl;
    
    
    
    
    return 0;
}