#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
int n;
string s,t;
bool get(int x1,int y1,int x2,int y2){
    string s;
    cout<<'?'<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    cout.flush();
    cin>>s;
    if( s=="BAD" )
        assert(0);
    if( s=="YES" )
        return 1;
    else
        return 0;
}
int main(){
    #ifdef LOCAL
     //   freopen ("test.in", "r", stdin);
    #endif
    cin>>n;
    pair<int,int> a;
    int k;

    a={1,1};
    k=n-1;
    while(k--){
        if( a.f<n && get(a.f+1,a.s,n,n) )
            a.f++,s+='D';
        else
            a.s++,s+='R';
    }
    a={n,n};
    k=n-1;
    while(k--){
        if( a.s>1 && get(1,1,a.f,a.s-1) )
            a.s--,t+='R';
        else
            a.f--,t+='D';
    }
    
    for(int i=0;i+i<t.size();i++)
        swap(t[i],t[t.size()-1-i]);
    
    cout<<"!"<<" "<<s<<t;
    cout.flush();
    return 0; 
}