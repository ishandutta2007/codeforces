#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
string s;
ll cnt[20],ans,cur[20];
ll f(ll n){
    if(n==0)
        return 1;
    return f(n-1)*n;
}
void get(int dg,int st){
    if(dg==10){                          
        ll res=0,sum=0;
        for(int i=0;i<10;i++)
            sum+=cur[i];
        res=f(sum-1);
        for(int i=0;i<10;i++){
            if(i==st)
                res/=f(cur[i]-1);
            else
                res/=f(cur[i]);
        }
        ans+=res;
        //for(int i=0;i<10;i++)
        //    cout<<cur[i]<<" ";cout<<endl;
        return;
    }
    if(cnt[dg]){
        for(int i=1;i<=cnt[dg];i++){
            cur[dg]=i;
            get(dg+1,st);   
        }
    }else
        get(dg+1,st);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>s;
    for(int i=0;i<s.size();i++)
        cnt[s[i]-'0']++;
    for(int i=1;i<10;i++){
        if(cnt[i]){
            get(0,i);
        }
    }
    cout<<ans;
}