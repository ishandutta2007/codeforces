#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false);
using namespace std;

int main()
{
    unsigned ll n;
    ll m,k;
    cin>>n>>m>>k;
    ll x,s;
    cin>>x>>s;
    vector<ll> ft(m);
    for(int i=0;i<m;i++)
    {
        cin>>ft[i];
    }
    vector<ll> fm(m);
    for(int i=0;i<m;i++)
    {
        cin>>fm[i];
    }
    vector<ll> secondno(k);
    vector<ll> sm(k);
    for(int i=0;i<k;i++)
    {
        cin>>secondno[i];
    }
    for(int i=0;i<k;i++)
    {
        cin>>sm[i];
    }
    unsigned ll mintime=n*x;
    for(int i=0;i<m;i++)
    {
        ll currentmana=s-fm[i];
        if(currentmana<0)
        {
            continue;
        }
        ll xnew=ft[i];
        ll index=0;
        if(upper_bound(sm.begin(),sm.end(),currentmana)!=sm.end())
        {
            index=upper_bound(sm.begin(),sm.end(),currentmana)-1-sm.begin();
        }
        else
        {
            index=k-1;
        }
        if(index<0)
        {
            unsigned ll temptime=n*xnew;
            if(temptime<mintime)
            {
                mintime=temptime;
            }
            continue;
        }
        ll currentn=n-secondno[index];
        if(currentn<=0)
        {
            mintime=0;
        }
        else
        {
            unsigned ll temptime=currentn*xnew;
            if(temptime<mintime)
            {
                mintime=temptime;
            }
        }
    }
    ll index=0;
    if(upper_bound(sm.begin(),sm.end(),s)!=sm.end())
    {
            index=upper_bound(sm.begin(),sm.end(),s)-1-sm.begin();
    }
    else
    {
            index=k-1;
        
    }
    if(index>=0)
    {
         ll currentn=n-secondno[index];
         if(currentn<=0)
         {
             mintime=0;
         }
         else
         {
             unsigned ll temptime=currentn*x;
             if(temptime<mintime)
             {
                 mintime=temptime;
             }
         }
    }
    cout<<mintime;
    return 0;
}