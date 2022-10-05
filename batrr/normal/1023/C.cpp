#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
int n,k,cur,was[maxn],close[maxn];
string s;
stack < int > st;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }else{
            close[st.top()]=i;
            st.pop();
        }
    }
    for(int i=0;i<n;i++)
        if(s[i]=='(' && k)
            was[i]=was[close[i]]=1,k-=2;
    for(int i=0;i<n;i++)
        if( was[i] )
            cout<<s[i];    
}