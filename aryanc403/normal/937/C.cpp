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
    LLI T,n,in,i,m,j,k,d,t;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>d>>t;
    
    if(k%d==0||k>=t)
    {
        cout<<t;
        return 0;
    }
    
    n = 2*t/(2*k+d-k%d);
    //cout<<n<<endl;
    T=n*(k+d-k%d);
    if(2*t - n*(2*k+d-k%d)<=2*k)
    {
        //double left=1.0-n*(k/(double)t+(d-k%d)/(double)(2*t));
        double ans=n*(d-k%d)+(t-n*((d-k%d)/(2.0)));
        printf("%.11f",ans);
    }
    else
    {
        T+=k;
        T+=2*t - 2*(n+1)*k-n*(d-k%d);
        cout<<T;
    }
    
    return 0;
}