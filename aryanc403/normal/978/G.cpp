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
    LLI T,n,in,i,m,j,k,s,d,sch[500],c;
    vector < pair < pair<LLI,LLI> , pair< LLI , LLI> > > a;//s,i,d,c
    vector <LLI> :: iterator it;
    bool poss;

bool cmp(const pair< pair<LLI,LLI> , pair<LLI,LLI> > &a,const pair< pair<LLI,LLI> , pair<LLI,LLI> > &b)
{
    return a.Y.X<b.Y.X;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
        a.clear();
        a.reserve(n);
        fo(i,m)
        {
            cin>>s>>d>>c;
            a.pb(mp(mp(s,i+1),mp(d,c)));
            sch[d]=m+1;
        }
    
    sort(a.begin(),a.end(),cmp);
    
    poss=true;
    for(i=0;i<m;++i)
    {
        for(j=a[i].X.X;j<a[i].Y.X;j++)
        {
            if(a[i].Y.Y==0)
            {
                break;
            }
            if(sch[j]==0)
            {
                sch[j]=a[i].X.Y;
                a[i].Y.Y--;
            }
        }
        if(a[i].Y.Y!=0)
        {
            poss=false;
            break;
        }
    }
    
    if(poss)
    {
        for(i=1;i<=n;++i)
            cout<<sch[i]<<" ";
    }
    else
    {
        cout<<-1;
    }
    
    return 0;
}