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

int n,k,was[maxn];
string s;
queue<int>q[2000];
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif  
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<s.size();i++)
        q[s[i]].push(i);
    for(int i=0;i<1000;i++)
        while(k>0 && !q[i].empty()){
            was[q[i].front()]=1;
            q[i].pop();
            k--;
        }
    for(int i=0;i<s.size();i++)
        if(!was[i])
            cout<<s[i];
}