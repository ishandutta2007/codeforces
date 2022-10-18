#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
#define F(i,x) for(int i=0;i<x;i++)
#define p(i,j) pair<i,j>
#define v(i) vector<i>
#define int long long

  bool les(p(p(int,int),int) a,p(p(int,int),int) b)
  {
        return ((a.first.first>b.first.first) || ((a.first.first==b.first.first) && (a.first.second<b.first.second)));
  }  
  bool lee(p(p(p(int,int),int),int) a,p(p(p(int,int),int),int) b) 
  {
        return ((a.first.first.second<b.first.first.second) || ((a.first.first.second==b.first.first.second) && (a.first.first.first<b.first.first.first)) );
  }
 main()
 {   
    int n,p,k;
    cin>>n>>p>>k;
    v(p(p(int,int),int)) a(n);
    F(i,n)
    a[i].second=i+1,cin>>a[i].first.second>>a[i].first.first;
    v(p(p(p(int,int),int),int)) b(n-(p-k));
    sort(a.begin(),a.end(),les);
    F(i,n-(p-k))
    b[i].first=a[i],b[i].second=i;
    sort(b.rbegin(),b.rend(),lee);
    F(i,k)
    cout<<b[i].first.second<<' ';
    int index=0;
    F(i,k)
    if(b[i].second>index)
    index=b[i].second;
    index++;
    F(i,p-k)
    cout<<a[index+i].second<<' ';
 }