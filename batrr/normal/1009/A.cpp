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
int n,m,x,ans;
queue<int>q1,q2;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>m;    
    while(n--){
        cin>>x;
        q1.push(x);
    }
    while(m--){
        cin>>x;
        q2.push(x);
    }
    while(!q1.empty()){
        if(!q2.empty() && q1.front()<=q2.front()){
            ans++;
            q2.pop();
        }
        q1.pop();
    }
    cout<<ans;
}