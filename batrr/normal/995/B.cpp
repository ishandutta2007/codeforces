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
ll n,ans,a[maxn];
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    IOS                                
    cin>>n;
    n*=2;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i+=2){
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]){
                while(j>i+1){
                    swap(a[j],a[j-1]);
                    j--;
                    ans++;
                }
                break;

            }
        }
       /* 
        for(int j=0;j<n;j++)
            cout<<a[j]<<" ";
        cout<<endl;
        */
    }

    cout<<ans;
    #ifdef LOCAL
        cout <<endl<< clock () * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}