#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int mod=998244353;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int po(int x,int y){
    int z=1;
    while(y){
        if(y&1){
            z=mul(z,x);
        }
        x=mul(x,x);
        y>>=1;
    }
    return z;
}
int main(){
	AquA;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt=0;
    for(auto h:s){
        cnt+=(h=='?');
    }
    const int g=17;
    vector<vector<int> > dp(g+1,vector<int>(1<<g));
    vector<vector<pair<int,pair<int,int> > > > a(n,vector<pair<int,pair<int,int> > >(n));
    for(int i=1;i<=n;i++){
        for(int l=0;l+i-1<n;l++){
            int r=l+i-1;
            if(i==1){
        		if(s[l]=='?'){
        			a[l][r].sc.sc++;
                    a[l][r].sc.fs++;
				}
			}
			else{
				a[l][r]=a[l+1][r-1];
	            if(s[l]==s[r]){
	                if(s[l]=='?'){
	                    a[l][r].sc.sc++;
                        a[l][r].sc.fs+=2;
	                }
	            }
	            else{
	                if(s[l]!='?' && s[r]!='?'){
	                    a[l][r].sc.sc=-48763;
	                }
	                else{
	                    int u=(s[l]+s[r]-'?'-'a');
	                    a[l][r].fs|=(1<<u);
                        a[l][r].sc.fs++;
	                }
	            }
			}
            if(a[l][r].sc.sc>=0){
                for(int k=__builtin_popcount(a[l][r].fs);k<=g;k++){
                    add(dp[k][a[l][r].fs],po(k,a[l][r].sc.sc+(cnt-a[l][r].sc.fs)));
                }
            }
        }
    }
    for(int i=0;i<=g;i++){
        for(int j=0;j<g;j++){
            for(int k=0;k<(1<<g);k++){
                if(k&(1<<j)){
                    add(dp[i][k],dp[i][k^(1<<j)]);
                }
            }
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        string z;
        cin >> z;
        int u=0;
        for(auto h:z){
            u|=(1<<(h-'a'));
        }
        cout << dp[z.length()][u] << "\n";
    }
    
	return 0;
}