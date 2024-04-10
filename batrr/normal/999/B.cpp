#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=1e6+123,LOG=18,inf=1e9,block=450,N=1e7;
const ll INF=1e18;

int n;
string s;
void rev(int l,int r){
    for(int i=0;l+i<r-i;i++)
        swap(s[l+i],s[r-i]);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif  
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        if(n%i==0)
            rev(0,i-1);
    cout<<s;
}