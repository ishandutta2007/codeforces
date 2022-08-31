#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  2e6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll t,n;
string s;

ll lpp(string s){
    string rev="",str=s;
    int m=s.size(),longestPalindromicPrefix=1;
    if(m==0 || m==1)    longestPalindromicPrefix=m; 
    for(int i=m-1;i>=0;i--)
        rev+=s[i];
    s+='#';
    s+=rev;
    int n=s.size(),z[n+4],l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r-l]==s[r])
                r++;
            z[i]=r-l,r--;
        }
        else{
            int k=i-l;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                l=i;
                while(r<n && s[r-l]==s[r])
                    r++;
                z[i]=r-l,r--;
            }
        }
    }

    for(int i=m+1;i<n;i++){
        if(2*z[i]>=2*m-i && z[i]>longestPalindromicPrefix)
            longestPalindromicPrefix=z[i];
    }
    return longestPalindromicPrefix;
}
 
int main(){
    fastio;
    cin>>t;
    while(t--){
        cin>>s;
        n = s.size();
        string ans = "";
        int i;
        for(i = 0; i*2 < n; i++){
            if(s[i] != s[n-i-1]) break;
            ans += s[i];
        }
        string res;
        for(int j = i; j <= n-i-1; j++){
            res += s[j];
        }
        ll a1 = lpp(res);
        reverse(res.begin(), res.end());
        ll a2 = lpp(res);
        res = ans;
        if(a1 > a2){
            for(int j = i; j < i+a1; j++){
                res += s[j];
            }
        }
        else{
            for(int j = n-i-1; j > n-i-1-a2; j--){
                res += s[j];
            }
        }
        reverse(ans.begin(), ans.end());
        ll nn = ans.size();
        if(i*2-1 == n) i = 1;
        else i = 0;
        for(; i < nn; i++)res += ans[i];
        cout<<res<<endl;
    }
}