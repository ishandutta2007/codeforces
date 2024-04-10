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
typedef pair<LLI,LLI> ii;
typedef vector<ii> vii;
typedef vector<LLI> vi;
const LLI INF = 0xFFFFFFFFFFFFFFFL;
    LLI T,n,in,i,m,j,k,p,q,b;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--)
    {
        cin>>p>>q>>b;
        LLI g = __gcd(p,q);
        p/=g;
        q/=g;
        g=__gcd(q,b);
        while(g!=1)
        {
            while(q%g==0)
            {
                q/=g;
            }
            g=__gcd(q,b);
        }
        
        if(q==1)
        {
            cout<<"Finite"<<endl;
        }
        else
        {
            cout<<"Infinite"<<endl;
        }
    }
    return 0;
}