//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2 ///////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
char s[3][3];
int x,o;
bool win[2],mark;
vector <pair <int,int> > v;
/*
bool check()
{
    for(int i=0;i<3;i++)
    {
        if(s[i][0]==s[i][1] && s[i][1]==s[i][2] && s[i][0]!='.')
            return 1;
        if(s[0][i]==s[1][i] && s[1][i]==s[2][i] && s[0][i]!='.')
            return 1;
    }
    if(s[0][0]==s[1][1]&& s[1][1]==s[2][2] && s[0][0]!='.')
        return 1;
    if(s[0][2]==s[1][1] && s[1][1]==s[2][0] && s[2][0]!='.')
        return 1;
    return 0;   
}

void dfs(int x,int y,int index)
{
    if(index==v.size())
    {
        if(check())
            mark=1;
        return ;
    }
    s[x][y]='X';
    dfs(v[index+1].first,v[index+1].second,index+1);
    s[x][y]='0';
    dfs(v[index+1].first,v[index+1].second,index+1);
    s[x][y]='.';
}
*/
int Sa1378
{ 
    IB
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='X')
                x++;
            else if(s[i][j]=='0')
                o++;    
        }   
    
    for(int i=0;i<3;i++)
    {
        if(s[i][0]==s[i][1] && s[i][1]==s[i][2] && s[i][0]!='.')
        {
            if(s[i][0]=='X')
                win[0]=1;
            else
                win[1]=1;   
        }
        if(s[0][i]==s[1][i] && s[1][i]==s[2][i] && s[0][i]!='.')
        {
            if(s[0][i]=='X')
                win[0]=1;
            else
                win[1]=1;   
        }
    }
    if(s[0][0]==s[1][1]&& s[1][1]==s[2][2] && s[0][0]!='.')
    {
            if(s[0][0]=='X')
                win[0]=1;
            else
                win[1]=1;   
    }
    if(s[0][2]==s[1][1] && s[1][1]==s[2][0] && s[2][0]!='.')
    {
            if(s[2][0]=='X')
                win[0]=1;
            else
                win[1]=1;   
    }
    
    if(abs(x-o)>1 || o>x || (win[0] && win[1]) || (win[1] && x>o) || (win[0] && x==o))
    {
        cout<<"illegal";
        return 0;
    }   
    if(win[0])
    {
        cout<<"the first player won";
        return 0;
    }   
    if(win[1])
    {
        cout<<"the second player won";
        return 0;
    }
    /*
    /// draw
    mark=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(s[i][j]=='.')
                v.push_back({i,j});
    if(v.size())            
        dfs(v[0].first,v[0].second,0);      
    */      
    if(x+o==9)
    {
        cout<<"draw";
        return 0;
    }
    if(x>o)
    {
        cout<<"second";
        return 0;
    }
    if(o==x)
    {
        cout<<"first";
        return 0;
    }
    
        
    return 0;
}