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

bool l(p(int,int) a,p(int,int) b)
{return a.first<b.first || ( (a.first==b.first) && a.second<b.second);}

 main()
 {   
    int n;
    cin>>n;
    v(p(int,int)) a(n);
    F(i,n)
    {
    cin>>a[i].second;
    a[i].first=i;
    }
    
    v(p(int,int)) b=a;
    F(i,n)
    swap(b[i].first,b[i].second);
    sort(b.begin(),b.end(),l);
    bool eq=0;
    F(i,n-1)
    if(b[i].first>=0 && b[i].first==b[i+1].first)
    eq=1;
    
    v(int) l_sum(n+1);
    l_sum[0]=0;
    for(int i=0;i<n;i++)
    {
    l_sum[i+1]=l_sum[i]+(a[i].second>0?a[i].second:0);
    }
    int max=-1e10,it1,it2;
    for(int i=0;i<n;i++)
    {
    int t1=i,t2=i;
    while(t2<n-1)
    if(b[t2+1].first!=b[t2].first)
    break;
    else
    t2++;
    int kk=l_sum[b[t2].second+1]-l_sum[b[t1].second]+(b[i].first<0?b[i].first*2:0);
    if(kk>max && t1!=t2)
    max=kk,it1=b[t1].second,it2=b[t2].second;
    i+=t2-t1;   
    }
    int c=0;
    for(int i=0;i<n;i++)
    if((a[i].second<0 && i!=it1 && i!=it2) || (i<it1) || (i>it2))
    c++;
    cout<<max<<' '<<c<<endl;
    for(int i=0;i<n;i++)
    if((a[i].second<0 && i!=it1 && i!=it2) || (i<it1) || (i>it2))
    cout<<a[i].first+1<<' ';
    
 }