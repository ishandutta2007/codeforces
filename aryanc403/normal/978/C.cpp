//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
#define MOD 1000000007
    LLI T,n,in,i,m,j,k;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI sum=0;
    cin>>n>>m;
    {
        a.clear();
        a.reserve(n);
        
        fo(i,n)
        {
            cin>>in;//scanf(" %lld",&in);
            sum+=in;
            a.pb(sum);
        }
    }
    while(m--)
    {
        cin>>in;
        //cout<<in<<"in";
        if(in<=a[0])
        {
            cout<<1<<" "<<in<<endl;
            continue;
        }
        
        if(in>a[n-2])
        {
            cout<<n<<" "<<in-a[n-2]<<endl;
            continue;
        }
        i=lower_bound(a.begin(),a.end(),in)-a.begin();
        cout<<i+1<<" ";
        cout<<in-a[i-1]<<endl;
    }
    
    return 0;
}