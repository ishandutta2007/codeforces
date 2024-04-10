#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
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
 
/* template<typename T> void merge(T&c,T&a,T&b)
{
    typeof(a.begin()) it1=a.begin(),it2=b.begin();
    tr(c,d)
    if(it1!=a.end() && (it2==b.end() || *it1<*it2 ) )
    *d=*it1++;
    else
    *d=*it2++;
}

template<typename T> void mergesort(T&a)
{   
    int n=a.size(),k=n/2;
    typeof(a.begin()) itb=a.begin();
    if(n==2)
    if(*a.begin()>*(++itb))
    swap(*a.begin(),*itb);
    if(n<3)
    return;
    T b(k),c(k+n%2);
    typeof(a.begin()) it1=b.begin(),it2=c.begin();
    int i=0;
    tr(a,it)
    (i++<k?*it1++:*it2++)=*it;
    mergesort(b);
    mergesort(c);
    merge(a,b,c);
}*/

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

void qsort(v(int)&a)
{
    int n=a.size();
    if(n==1 || n==0)
    return;
    int rand_elem=rand()%n;
    v(int) b,c;
    b.reserve(n);
    c.reserve(n);
    int c_b=0;
    F(i,n)
    if(a[i]<a[rand_elem])
    b.pb(a[i]);
    else 
    {c.pb(a[i]);if(a[i]>a[rand_elem])c_b++;}
    qsort(b);
    if(c_b)
    qsort(c);
    a=b;
    a.insert(a.end(),all(c));
}

void csort(v(int)&a,int n)
{
    v(int) x(n,0);
    F(i,a.size())
    x[a[i]+n/2]++;
    int c=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<x[i];j++)
    a[c++]=i-n/2;
}

/*--------- SOLUTION ---------*/
     
 main()
 {   
    int n,k;
    cin>>n>>k;
    int*a=new int[n];
    F(i,n)
    cin>>a[i];
    
    int*s=new int[n-k+1];
    s[0]=0;
    F(i,k)
    s[0]+=a[i];
    for(int i=1;i<=n-k;i++)
    s[i]=s[i-1]-a[i-1]+a[i+k-1];
    
    int*rmaxi=new int[n-k];
    rmaxi[n-k-1]=n-k;
    for(int i=1;i<n-k;i++)
     rmaxi[n-k-i-1]=s[n-k-i]>=s[rmaxi[n-k-i]]?n-k-i:rmaxi[n-k-i];
    int maxi=0,maxe=0;
    //F(i,n-k)
    //cout<<rmaxi[i]<<endl;
    //cout<<"next"<<endl;
    F(i,n-2*k+1)
    {
        //cout<<i<<endl;
    int cur=s[i]+s[rmaxi[i+k-1]];
     if(cur>maxe)   
     maxe=cur,maxi=i;
    }
    cout<<maxi+1<<' '<<rmaxi[maxi+k-1]+1<<endl;
    //system("pause");
 }