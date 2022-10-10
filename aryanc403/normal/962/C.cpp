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
    LLI T,n,in,i,m,j,a,b;
    string s;
    vector <LLI> :: iterator it;

LLI find(string s)
{
    if(s.size()<=0)
        return MOD;
    
    LLI c=0;
    
    fo(i,s.size())
    {
        c*=10;
        c+=s[i]-'0';
    }
    
    LLI l=sqrt(c);
    
    if(c==0)
        return MOD;
    
    if(l*l==c&&s[0]!='0')
    {
        //cout<<s<<endl;
        return 0;
    }
    LLI cnt=MOD;
    l=s.size();
    LLI i=0;
    fo(i,l)
    {
        //cout<<s.substr(0,i)+s.substr(i+1,l-i-1)<<endl;
        cnt=min(cnt,1+find(s.substr(0,i)+s.substr(i+1,l-i-1)));
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    
    LLI m=find(s);
    //cout<<s.substr(0,4)+s.substr(4+1);
    if(m==MOD)
    {
        cout<<-1;
    }
    else
    {
        cout<<m;
    }
    
    return 0;
}