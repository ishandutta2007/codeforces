#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define vl vector<long long>

#define vi vector<int> 
#define vii vector< vector<int> >
#define vll vector< vector<long long> >
#define vpi vector< pair<ll,ll> >
#define MAXN 100001  
#define mod %1000000007

int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
     freopen("int.txt","r",stdin);
     freopen("out.txt","w",stdout);
     #endif
    int x1,y1;
    int x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int t;
   if(x1==x2)
   {
        t=2*(abs(y1-y2)-1)+8;
        cout<<t;
   }
   else
    if(y1==y2)
    {
        t=2*(abs(x1-x2)-1)+8;
        cout<<t;
    }
    else
    {
        cout<<2*(abs(x1-x2)+1)+2*(abs(y1-y2)+1);
    }
    

    return 0;
        

}