#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
int n,m,pre,suf,ok=-1,was[maxn];
string s,t;       
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
                                 
    cin>>n>>m;
    cin>>s>>t;
    for(int i=0;i<n;i++)
        if(s[i]=='*')
            ok=i;

    if(ok==-1){
    if(s==t)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
    }
    for(int i=0;i<ok;i++){
        if(s[i]!=t[i]  || was[i]){
            cout<<"NO";
            return 0;
        }
        was[i]=1;
    }
    for(int i=n-1,j=m-1;i>ok;i--,j--){
        if(s[i]!=t[j]  || was[j]){
            cout<<"NO";
            return 0;
        }
        was[j]=1;
    }
    cout<<"YES";


}