#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
/*--------- PRE_SOL ---------*/
/*--- Rewrite every month ---*/
 
#define tr(c, it)  for(typeof(c.begin()) it=c.begin();  it != c.end(); it++)
#define rall(c) c.rbegin(),c.rend()
#define F(i,x) for(int i=0;i<x;i++)
#define all(c) c.begin(),c.end()
#define pb(i) push_back(i)
#define p(i,j) pair<i,j>
#define v(i) vector<i>
#define ld long double
#define int long long
 
 template<typename T, typename T2> bool present(const T& c, const T2& obj) 
 {
    return find(all(c),(T)(obj)) != c.end();
 }
 
 template<typename T, typename T2> bool present(const set<T>& c, const T2& obj) 
 {
    return c.find((T)(obj)) != c.end();
 }

 int binary_search(const v(int)&a, int x,bool u)
 {
    int n=a.size();
    int f=0,l=n,m;
    while(f<l)
    {
        m=f+(l-f)/2;
        if(u?a[m]>=x:a[m]>x)
        l=m;
        else
        f=m+1;
    }
    return l;
 }

const ld eps=1e-8;
 ld func(ld a,ld b,ld c,ld d,ld x)
 {return a*x*x*x+b*x*x+c*x+d;}
 ld func_bin(ld a,ld b,ld c,ld d, ld f,ld l)
 {
    if((func(a,b,c,d,f)<0.0 && func(a,b,c,d,l)<0.0) || (func(a,b,c,d,f)>0.0 && func(a,b,c,d,l)>0.0))
    return 1e4;
    if(0.0>=f && 0.0<=l && (fabs(func(a,b,c,d,0))<eps))
    return 0;
    ld m;
    bool u=func(a,b,c,d,l)<=func(a,b,c,d,f);
    while(fabs(l-f)>1e-15)
    {
        m=f+(l-f)/2;
        if((u?-1:1)*func(a,b,c,d,m)>0.0)
        l=m;
        else
        f=m;
    }
    return m;
 }
 
/*--------- SOLUTION ---------*/
vector<int> used(1000001,0);
int solve(int k,int n)
{  
    if(used[n])
    return k+used[n];
    v(int) a;
    int t=n;
    while(t)
    a.pb(t%10),t/=10;
    v(int) b;
    if(a.size()==1)
    {used[n]=0;return k;}
    used[n]=solve(k+1,n-*max_element(a.begin(),a.end()))-k;
    return k+used[n];
}

 main()
 {   
    int n;
    cin>>n;
    if(n==0)
    {cout<<0<<endl;return 0;}
    int t;
    for(int i=1;i<n;i++)
    solve(1,i);
    cout<<solve(1,n)<<endl;
 }