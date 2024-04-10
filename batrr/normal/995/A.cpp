#include <bits/stdc++.h>
/*
#pragma GCC optimize("Ofast")
  */
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=4001,mod=998244353;
int n,k,a[100][2],b[100][2];
vector< pair<int,int> >v;
vector< pair<int,pair<int,int> > >ans;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>n>>k;        
    for(int i=1;i<=n;i++)
        cin>>b[i][0];
    for(int i=1;i<=n;i++)
        cin>>a[i][0];
    for(int i=1;i<=n;i++)
        cin>>a[i][1];
    for(int i=1;i<=n;i++)
        cin>>b[i][1]; 
    for(int i=1;i<=n;i++)
        v.pb(mp(i,0));
    for(int i=n;i>=1;i--)
        v.pb(mp(i,1));
    for(int i=0;i<4*n;i++)
        v.pb(v[i]);
    while(k){
        for(int i=1;i<=n;i++){
            if(a[i][0]!=0 && a[i][0]==b[i][0]){
                k--;
                ans.pb(mp(a[i][0],mp(1,i)));
                a[i][0]=0;
                b[i][0]=0;
            }
            if(a[i][1]!=0 && a[i][1]==b[i][1]){
                k--;
                ans.pb(mp(a[i][1],mp(4,i)));
                a[i][1]=0;
                b[i][1]=0;
            }
        }   
        
        bool ok=0;
        for(int i=1;i<=2*n;i++){
            if(a[v[i].f][v[i].s]==0){
                for(int j=i;j<i+2*n;j++)
                    if(a[v[j].f][v[j].s]!=0){
                        ans.pb(mp(a[v[j].f][v[j].s],mp(v[j-1].s+2,v[j-1].f)));
                        swap(a[v[j].f][v[j].s],a[v[j-1].f][v[j-1].s]);
                    }    
                ok=1;
                break;
            }
        }
        if(!ok)
            cout<<-1,exit(0);        
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)
        cout<<x.f<<" "<<x.s.f<<" "<<x.s.s<<endl;
}