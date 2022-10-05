#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e9,mod=1e9+7,N=360360;
int n,m,ans,cnt;
vector< vector< char > >  s;
vector< vector< vector< int > > > p,P;
void precalc(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            p[i][j][0]=p[i][j][1]=i,
            p[i][j][2]=p[i][j][3]=j;
}

int getp(int i,int j,int k){
    if( k&2 ){
        if( p[i][j][k]==j || p[i][j][k]==inf)
            return p[i][j][k];
        return p[i][j][k]=getp(i,p[i][j][k],k);
    }else{
        if( p[i][j][k]==i || p[i][j][k]==inf)
            return p[i][j][k];
        return p[i][j][k]=getp(p[i][j][k],j,k);
    }
}
int get(int i,int j){
    int res=0;
    while(true){                        
       // cout<<i<<" "<<j<<endl;
        p[i][j][0]=P[i][j][0];
        p[i][j][1]=P[i][j][1];
        p[i][j][2]=P[i][j][2];
        p[i][j][3]=P[i][j][3];
        res++;
        if(s[i][j]=='U'){
            i=getp(i,j,0);
            if(i==inf)
                break;
            continue;
        }
        if(s[i][j]=='D'){
            i=getp(i,j,1);
            if(i==inf)
                break;
            continue;
        }
        if(s[i][j]=='L'){
            j=getp(i,j,2);
            if(j==inf)
                break;
            continue;
        } 
        if(s[i][j]=='R'){
            j=getp(i,j,3);
            if(j==inf)
                break;
            continue;
        } 
    }
    return res;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    //    freopen (".out", "w", stdout);
    #endif
    scanf("%d %d\n",&n,&m);
    s.resize( n , vector<char> (m) );                             
    p.resize( n , vector< vector<int> > ( m , vector<int> (4) ) );
    P.resize( n , vector< vector<int> > ( m , vector<int> (4) ) ); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            scanf("%c",&s[i][j]);
        scanf("\n");
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int q;
            
            q=i+1;
            while( q<n && s[q][j]=='.')
                q++;
            if(q==n)
                q=inf;
            P[i][j][1]=q;

            q=i-1;
            while( q>=0 && s[q][j]=='.')
                q--;
            if(q==-1)
                q=inf;
            P[i][j][0]=q;       

            q=j+1;
            while( q<m && s[i][q]=='.')
                q++;
            if(q==m)
                q=inf;
            P[i][j][3]=q;
            
            q=j-1;
            while( q>=0 && s[i][q]=='.')
                q--;
            if(q==-1)
                q=inf;
            P[i][j][2]=q;
        }
    }

    ans=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if( s[i][j]!='.'){
                precalc();
                int cur=get(i,j);
                if(cur>ans)
                    ans=cur,cnt=0;
                if(cur==ans)
                    cnt++;
            }              
    printf("%d %d",ans,cnt); 
}