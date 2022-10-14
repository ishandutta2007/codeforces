// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 


#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
map<char,char>a;
bool valid(string s,int h,int m)
{
    fi(s.size())
    {
        if(s[i]!=':')
        {
            if(s[i]!='0'&&s[i]!='1'&&s[i]!='2'&&s[i]!='5'&&s[i]!='8'){
                
                return false;
            }
        }
    }
    string p=s.substr(0,2);
    string q=s.substr(3,2);

    reverse(all(p));
    fi(p.size())
    {
        if(p[i]=='2')
            p[i]='5';
        else if(p[i]=='5')
            p[i]='2';
    }
    reverse(all(q));
    fi(q.size())
    {
        if(q[i]=='2')
            q[i]='5';
        else if(q[i]=='5')
            q[i]='2';
    }
    int h1=stoi(q);
    int m1=stoi(p);

    if(h1>=h||m1>=m)
        return false;

    return true;
}
string Increement(string &s,int h,int m)
{
    string p=s.substr(0,2);
    string q=s.substr(3,2);
    int h1=stoi(p);
    int m1=stoi(q);
    if(m1==m-1){
        m1=0;
        h1++;
    }
    else
        m1++;
    if(h1>=h)
        h1=0;
    string s1=to_string(h1);
    if(s1.size()==1){
        s1+="0";
        reverse(all(s1));
    }
    s1+=":";
    string s2=to_string(m1);
    if(s2.size()==1){
        s2+="0";
        reverse(all(s2));
    }
    s1+=s2;
    s=s1;
    return s1;
}
string convertToReflection(string s)
{
    string p=s;
    fi(s.size())
    {
        if(s[i]!=':')
        p[p.size()-i-1]=a[s[i]];
    }
    return p;
}
int32_t main()
{
    aeh();
    a.insert({'0','0'});
    a.insert({'2','5'});
    a.insert({'1','1'});
    a.insert({'5','2'});
    a.insert({'8','8'});
    int t;cin>>t;
    while(t--)
    {
        int h,m;cin>>h>>m;
        string s;cin>>s;
        while(!valid(s,h,m))
        {   
            s=Increement(s,h,m);
        }
        
        cout<<s<<endl;       
    }
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}