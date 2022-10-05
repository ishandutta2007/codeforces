#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
string s,t;
vector< pair<int,int> > ans,a,b;
vector< pair<int,int> > vec(string s){
    vector< pair<int,int> >res;
    for(int i=0;i<s.size();i++){
        if(i!=0 && s[i]==s[i-1])
            res[res.size()-1].s++;
        else
            res.pb({(s[i]=='a'),1});    
    }
    reverse(res.begin(),res.end());
    return res;
}
void prefswap( vector<pair<int,int> > &a,vector< pair<int,int> > &b,int k1,int k2){
    vector< pair<int,int> > q,w;
    int s1=0,s2=0;
    while(k1--){
        q.pb(a.back());
        s1+=a.back().s;
        a.pop_back();
    }
    while(k2--){
        w.pb(b.back());
        s2+=b.back().s;
        b.pop_back();
    }

    ans.pb({s1,s2});

    while(!q.empty()){
        if(b.empty() || b.back().f!=q.back().f )
            b.pb(q.back());
        else
            b[b.size()-1].s+=q.back().s;    
        q.pop_back();
    }       

    while(!w.empty()){
        if(a.empty() || a.back().f!=w.back().f )
            a.pb(w.back());
        else
            a[a.size()-1].s+=w.back().s;    
        w.pop_back();
    }               
    

}
void print( vector< pair<int,int> > a, vector< pair<int,int> > b){
    for(int i=a.size()-1;i>=0;i--){
        while(a[i].s--)
            if(a[i].f)    
                cout<<'a';
            else
                cout<<'b';
    }
    cout<<endl;

    for(int i=b.size()-1;i>=0;i--){
        while(b[i].s--)
            if(b[i].f)    
                cout<<'a';
            else
                cout<<'b';
    }
    cout<<endl;

}
int get(int len,int mn,int pl){
    len-=mn;
    if(len==0)
        return pl;
    return len+pl-1;
}
bool check(int a,int b){ 
    if( b==1 )
        return 0;
    if( a%2==0 && a/2%2==0 && b%2==1 && b/2%2==0 )
        return 1;
    if( a%2==1 && a/2%2==0 && b%2==0 && b/2%2==1 )
        return 1;
    if( a%2==0 && a/2%2==1 && b%2==1 && b/2%2==1 )
        return 1;
    if( a%2==1 && a/2%2==1 && b%2==0 && b/2%2==0 )
        return 1;
    return 0;
}
int main(){
    #ifdef LOCAL
       freopen ("test.in", "r", stdin);
    #endif        
    IOS
    cin>>s>>t;
    a=vec(s);
    b=vec(t);
    if( a.size()==b.size() && a.size()==1 )
        cout<<0,exit(0);
    if(a.back().f!=b.back().f){
        if( a.size() < b.size() ){
            int id=1;
            for(int i=1;i<=b.size();i+=2)
              if( max( get(a.size(),1,i) , get(b.size(),i,1) ) < max( get(a.size(),1,id) , get(b.size(),id,1) ) )
                id=i;
            prefswap(a,b,1,id);
        }else{
            int id=1;
            for(int i=1;i<=a.size();i+=2)
              if( max( get(b.size(),1,i) , get(a.size(),i,1) ) < max( get(b.size(),1,id) , get(a.size(),id,1) ) )
                id=i;   
            prefswap(a,b,id,1);
        }
        while(a.size()>1 || b.size()>1 )
           prefswap(a,b,1,1);
    
    }else{
        if( a.size() < b.size() ){
            
            if( check(b.size(),a.size()) )
                prefswap(a,b,1,2);
            
            int id=(int)(b.size()-a.size())/2+1;
            if( id%2==0 )
                id--;
            prefswap(a,b,0,id);
        }else{
            if( check(a.size(),b.size()) )
                prefswap(a,b,2,1);

            int id=(a.size()-b.size())/2+1;
            if( id%2==0 )
                id--;
            
            prefswap(a,b,id,0);
        }
        
        while(a.size()>1 || b.size()>1 )
           prefswap(a,b,1,1);
    
    }
        
    cout<<ans.size()<<endl;
    for(auto x:ans)
        cout<<x.f<<" "<<x.s<<endl;
}