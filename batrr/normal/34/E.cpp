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
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e9,mod=1e9+7,N=360360;
int n;
double t,x[15],v[15],m[15];
vector< pair<int,int> >vec;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    //    freopen (".out", "w", stdout);
    #endif
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>x[i]>>v[i]>>m[i];
        vec.pb({x[i],i});
    }
    sort(vec.begin(),vec.end());
    while(true){
        double nxt=1e9;
        for(int i=0;i+1<vec.size();i++){
            int id1=vec[i].s,id2=vec[i+1].s;
            double cur= (x[id1]-x[id2])/(v[id2]-v[id1]);
            if(cur>0)
                nxt=min(nxt,cur);
        }
        if( t < nxt )
            break;
        for(int i=0;i<n;i++)
            x[i]+=v[i]*nxt;
        
        for(int i=0;i+1<vec.size();i++){
            int id1=vec[i].s,id2=vec[i+1].s;
            
            if( x[id1]==x[id2] ){
                double v1=v[id1],v2=v[id2];
                double m1=m[id1],m2=m[id2];               
                v[id1]=( (m1-m2)*v1 + 2*m2*v2 )/(m1+m2);
                v[id2]=( (m2-m1)*v2 + 2*m1*v1 )/(m1+m2);
            }    
        }
        t-=nxt;
    }
    cout<<fixed<<setprecision(20);
    for(int i=0;i<n;i++)
        cout<<x[i]+v[i]*t<<endl;
    
}