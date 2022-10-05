#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;

ll n,a,b,c,d;
string s,t;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>s>>t;
    /*
    10
    00

    10
    01

    10
    10

    

    */
    for(int i=0;i<n;i++){          
        if( s[i]=='1' && t[i]=='0')
            a++;
        if( s[i]=='1' && t[i]=='1')
            b++;
        if( s[i]=='0' && t[i]=='0')
            c++;
        if( s[i]=='0' && t[i]=='1')
            d++;
    }
    cout<<a*c+a*d+b*c;
}