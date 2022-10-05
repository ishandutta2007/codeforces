#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;

int main(){
    #ifdef LOCAL
    //    freopen ("test.in", "r", stdin);
    #endif                                     
    int n,cur;
    cin>>n;
    cur=1;
    for(int i=1;i<=n;i++)
        if( i+(n+i-1)/i < cur+(n+cur-1)/cur)
            cur=i;
    for(int i=1;i<=n;i+=cur){
        for(int j=0;i+j<=n && j<cur;j++)
            cout<<min(n,i+cur-1)-j<<" ";
    }
}