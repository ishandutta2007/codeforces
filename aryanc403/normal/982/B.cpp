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
    vii a,b;
    vi :: iterator it;

bool cmp(const ii &a,const ii &b)
{
    return a.Y>b.Y;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
        cin>>n;//scanf(" %lld",&n);
        //cout<<n<<endl;
        a.clear();
        a.reserve(n);
        b.clear();
        b.reserve(n);
        fo(i,n)
        {
            cin>>in;//scanf(" %lld",&in);
            a.pb(mp(i+1,in));
            //cout<<in<<" ";
        }
    sort(a.begin(),a.end(),cmp);
    cin>>s;
    /*fo(i,n)
    {
        cout<<a[i].X<<" ";
    }*/
    //cout<<s;
    //return 0;
    k=n;
    n*=2;
    j=0;
    fo(i,n)
    {
        if(s[i]=='0')
        {
            //cout<<"zero";
            k--;
            cout<<a[k].X<<" ";
            b.pb(mp(a[k].X,a[k].Y));
            j++;
        }
        else
        {
            j--;
            cout<<b[j].X<<" ";
            b.pop_back();
        }
    }
    return 0;
}