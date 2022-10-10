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

bool isPrime(LLI n)
{
    if(n==2)
        return true;
    if(n<2||n%2==0)
        return false;
    
    LLI lim=sqrt(n);
    for(LLI i=3;i<=lim;i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    
    for(m=1;m<=1000;++m)
    {
        if(isPrime(n*m+1)==false)
        {
            cout<<m;
            return 0;
        }
    }
    
    return 0;
}