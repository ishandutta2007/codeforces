//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;
    lli T,n,in,i,m,j,k;
    vi a,pri;
    vi :: iterator it;
    bool vis[1000005];
lli priM(lli N)
{
    lli cnt=0;
    for(i=2;i<=N;++i)
    {
        if(vis[i])
            continue;
        pri.pb(i);
        cnt++;
        for(j=i*i;j<=N;j+=i)
        {
            vis[j]=true;
        }
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>n;
    cin>>s;
    //cout<<n<<" "<<s;
    if(n==1&&s[0]=='0')
    {
        cout<<"No";
        return 0;
    }
    fo(i,n)
    {
        if(i>0&&s[i-1]=='1'&&s[i]=='1')
        {
            cout<<"No";
            return 0;
        }
        
        if(i>1&&s[i-1]=='0'&&s[i]=='0'&&s[i-2]=='0')
        {
            cout<<"No";
            return 0;
        }
    }
    
    if(n>1&&(s[n-1]=='0'&&s[n-2]=='0'||s[0]=='0'&&s[1]=='0'))
    {
        cout<<"No";
        return 0;
    }
    
    //cout<<cnt;
    cout<<"Yes";
    return 0;
}