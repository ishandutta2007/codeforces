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

string s,a,b;
bool ok;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')
            a+=s[i];
        else
            b+=s[i];
    }
    for(int i=0;i<b.size();i++){
        if(!ok && b[i]=='2'){
            cout<<a;
            ok=1;
        }
        cout<<b[i];
    }
    if(!ok)
        cout<<a;
}