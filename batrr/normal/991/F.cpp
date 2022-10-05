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

const ll maxn=1e5+123,inf=1e18,mod=1e9+7,N=360360;
ll n;
string ans;
vector< ll > pws;
map< ll , string > pw;
string tostring(ll x){
    if(x==0)
        return "0";
    string res="";
    while(x)
        res=(char)(x%10+48)+res,x/=10;
    return res;
}
void MN(string x){
    if(x.size()<ans.size())
        ans=x;
}
void check(ll x,string s){      
    if(n/x==0)
        return;
    if(n/x!=1)
        s=tostring(n/x)+'*'+s;
    if(n%x==0)
        MN(s);
    else{
        if( !pw[n%x].empty() )
            MN(s+'+'+pw[n%x]);    
        MN(s+'+'+tostring(n%x));    
    }

}
ll mpow(ll a,ll b){
    ll res=1;
    while(b--)
        res*=a;
    return res;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>n;
    ans=tostring(n);
    for(int i=2;i<maxn;i++){
        ll x=1,p=0;
        while(x*i<=1e10){
            x*=i,p++;
            if(p>=2){
                pws.pb(x);
                string cur=tostring(i)+'^'+tostring(p);
                if(pw[x].empty() || pw[x].size()>cur.size())
                pw[x]=cur;
            }
        }
    }
    for(auto x:pws)
        check(x,pw[x]);
    for(ll a=1;a<10;a++)
        for(ll b=1;b<10;b++)
            for(ll x=2;x<10;x++)
                for(ll y=2;y<10;y++){
                    if( pow(x,a)*pow(y,b) <= n ){
                        string t=tostring(n-(ll)(mpow(x,a)*mpow(y,b)));
                        if(t=="0")
                            t="";
                        else
                            t='+'+t;
                        if( a==1 && b==1 ){
                            MN(tostring(x)+'*'+tostring(y)+t);        
                        }
                        if( a==1 ){
                            MN(tostring(x)+'*'+tostring(y)+'^'+tostring(b)+t);        
                        }
                        if( b==1 ){
                            MN(tostring(x)+'^'+tostring(a)+'*'+tostring(y)+t);        
                        }
                        MN(tostring(x)+'^'+tostring(a)+'*'+tostring(y)+'^'+tostring(b)+t);        
                        

                    }
                }
    cout<<ans;
}