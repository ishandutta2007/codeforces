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
    LLI T,n,in,i,m,j,cnt[3],cnt2[3],z,se[3][256],l;
    vector <LLI> a,b,c;
    vector <LLI> :: iterator it;
    string s;

LLI findMax()
{
    LLI m=max(cnt[0],max(cnt[1],cnt[2]));
    LLI c=0;
    
    for(LLI z=0;z<3;++z)
    {
        c+=cnt[z]==m;
    }
    
    if(c>1)
        return 3;
    
    if(cnt[0]>cnt[1]&&cnt[0]>cnt[2])
        return 0;
    if(cnt[1]>cnt[0]&&cnt[1]>cnt[2])
        return 1;
    if(cnt[2]>cnt[1]&&cnt[2]>cnt[0])
        return 2;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    z=3;
    cin>>n;
    while(z--)
    {
        cin>>s;
        l=s.size();
        fo(i,l)
        {
            se[z][s[i]]++;
            cnt[z]=max(cnt[z],se[z][s[i]]);
        }
    }
    
    fo(z,3)
    {
        if(n==1&&cnt[z]==l)
            cnt[z]--;
        else
        {
            cnt[z]=min(cnt[z]+n,l);
        }
    }
    
    z=findMax();
    if(z==0)
    {
        cout<<"Katie";
    }
    else if(z==1)
    {
        cout<<"Shiro";
    }
    else if(z==2)
    {
        cout<<"Kuro";
    }
    else if(z==3)
    {
        cout<<"Draw";
    }
    
    return 0;
}