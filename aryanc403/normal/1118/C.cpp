/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  Author - Aryan Choudhary (@aryanc403)
 
  const short DEBUG { 0 };
  #define debug(x) if (DEBUG) cout << #x << " = " << x << '\n'
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

//const lli [3] ={ 999119999L,1000000007L,1000992299L};
//const lli [3] ={ 97L,101L,103L};
//const lli  = chrono::high_resolution_clock::now().time_since_epoch().count();
clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class CMP
{
public:
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return ! ( a <= b );
    }
};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,cnt));
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r;
    lli m[25][25];
    string s;
    map<lli,lli> a;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void set2(lli x)
{
    lli i,j;
    // assert(n%2==1);
    repA(i,1,n/2)
    {
        if(m[(n+1)/2][i]==0)
        {
            m[(n+1)/2][i]=m[(n+1)/2][n-i+1]=x;
            // cout<<"set2 ";
            // cout<<"{"<<(n+1)/2<<","<<i<<"} ";
            // cout<<"{"<<(n+1)/2<<","<<n-i+1<<"} ";
            // cout<<endl;
            return;
        }
        else if(m[i][(n+1)/2]==0)
        {
            m[i][(n+1)/2]=m[n-i+1][(n+1)/2]=x;
            // cout<<"set2 ";
            // cout<<"{"<<i<<","<<(n+1)/2<<"} ";
            // cout<<"{"<<n-i+1<<","<<(n+1)/2<<"} ";
            // cout<<endl;
            return;
        }
    }
}

bool set4(lli x)
{
    lli i,j;
    repA(i,1,n/2)
    repA(j,1,n/2)
        if(m[i][j]==0)
        {
            m[i][j]=m[i][n-j+1]=m[n-i+1][j]=m[n-i+1][n-j+1]=x;
            // cout<<"set4 ";
            // cout<<"{"<<i<<","<<j<<"} ";
            // cout<<"{"<<n-i+1<<","<<j<<"} ";
            // cout<<"{"<<n-i+1<<","<<n-j+1<<"} ";
            // cout<<"{"<<i<<","<<n-j+1<<"} ";
            // cout<<endl;
            return true;
        }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    fo(i,n*n)
    {
        cin>>in;
        add(a,in);
    }
    
    if(n%2)
    {
        bool fl=false;
        for(auto x:a)
        {
            if(x.Y%4)
            {
                if(x.Y%2)
                {
                    if(fl)
                    {
                        cout<<"NO"<<endl;
                        return 0;
                    }
                    fl=true;
                }
                if(x.Y%4>1)
                    cnt++;
            }
        }
        
        if(cnt>n-1)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        
    }
    else
    {
        for(auto x:a)
        {
            if(x.Y%4)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"YES"<<endl;
    for(auto x:a)
    while(x.Y)
    {
        if(x.Y%2)
        {
            m[(n+1)/2][(n+1)/2]=x.X;
            x.Y--;
        }
        else if(x.Y%4==2)
        {
            set2(x.X);
            x.Y-=2;
        }
        else
        {
            if(!set4(x.X))
            {
                set2(x.X);
                set2(x.X);
            }
            x.Y-=4;
        }
    }
    
    repA(i,1,n)
    {
        repA(j,1,n)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    
}   aryanc403();
    return 0;
}