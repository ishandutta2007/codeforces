//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//int a[100005];
//vector <int> lsh;
//vector <int> lshx;
//int b[100005];
//vector <pii> res;
//
//inline void insert(int x,int y)
//{
//    res.push_back(mp(y+1,lshx[x]+1));
//}
//
//inline void print()
//{
//    cout<<res.size()<<endl;
//    for(auto &o:res)
//    {
//        printf("%d %d\n",o.first,o.second);
//    }
//    exit(0);
//}
//
//inline void error()
//{
//    cout<<-1<<endl;
//    exit(0);
//}
//
//int main()
//{
//    // freopen("input.txt","r",stdin);
//    cin>>n;
//    for(int i=0;i<n;i++)
//    {
//        scanf("%d",b+i);
//        if(b[i]) lsh.push_back(b[i]),lshx.push_back(i);
//    }
//    for(int i=0;i<(int)lsh.size();i++)
//    {
//        a[i]=lsh[i];
//    }
//    n=lsh.size();
//    if(n==0) print();
//    vector <int> v1;
//    int row=n-1;
//    int lst=-1,lsttype=-1;
//    for(int i=n-1;i>=0;i--)
//    {
//        // cout<<a[i]<<'-';
//        if(a[i]==1)
//        {
//            v1.push_back(i);
//            if(lst==-1) lst=i,lsttype=1;
//        }
//        else if(a[i]==2)
//        {
//            if(v1.empty()) error();
//            int x=v1.back();
//            v1.pop_back();
//            insert(i,row);
//            insert(x,row);
//            lst=i;
//            lsttype=2;
//            row--;
//        }
//        else
//        {
//            assert(a[i]==3);
//            if(lst==-1) error();
//            if(lsttype==1)
//            {
//                lst=v1.back();
//                v1.pop_back();
//                insert(lst,row);
//                row--;
//            }
//            insert(lst,row);
//            insert(i,row);
//            row--;
//            lsttype=3;
//            lst=i;
//        }
//    }
//    while(v1.size())
//    {
//        int x=v1.back();
//        v1.pop_back();
//        insert(x,row);
//        row--;
//    }
//    print();
//    return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_CONTROL_OF_MOD
int mod;
#else
const int mod=998244353;
#endif
const int gmod=2;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
using namespace std;
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<(int)vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T> 
void operator *= (vector <T> &vec,int k)
{
	for(auto &x:vec) x*=k;
}

template <typename T>
void operator -= (vector <T> &a,const vector <T> &b)
{
	assert(a.size()==b.size());
	for(size_t it=0;it<a.size();it++)
	{
		a[it]-=b[it];
	}
}

template <typename T>
vector <T> operator * (const vector <T> &vec,int k)
{
	vector <T> res(vec);
	res*=k;
	return res;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T,typename T2>
ostream & operator << (ostream & cout,set <T,T2> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2,typename T3>
ostream & operator << (ostream &cout,map <T1,T2,T3> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
		}
	}
	return v;
}
#endif

void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
using namespace std;
int n;
int a[100005];
vector <int> lsh;
vector <int> lshx;
int b[100005];
vector <pii> res;

inline void insert(int x,int y)
{
    res.push_back(mp(y+1,lshx[x]+1));
}

inline void print()
{
    cout<<res.size()<<endl;
    for(auto &o:res)
    {
        printf("%d %d\n",o.first,o.second);
    }
    exit(0);
}

inline void error()
{
    cout<<-1<<endl;
    exit(0);
}

int main()
{
    // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",b+i);
        if(b[i]) lsh.push_back(b[i]),lshx.push_back(i);
    }
    for(int i=0;i<(int)lsh.size();i++)
    {
        a[i]=lsh[i];
    }
    n=lsh.size();
    if(n==0) print();
    vector <int> v1;
    int row=n-1;
    int lst=-1,lsttype=-1;
    for(int i=n-1;i>=0;i--)
    {
        // cout<<a[i]<<'-';
        if(a[i]==1)
        {
            v1.push_back(i);
            if(lst==-1) lst=i,lsttype=1;
        }
        else if(a[i]==2)
        {
            if(v1.empty()) error();
            int x=v1.back();
            v1.pop_back();
            insert(i,row);
            insert(x,row);
            lst=i;
            lsttype=2;
            row--;
        }
        else
        {
            assert(a[i]==3);
            if(lst==-1) error();
            if(lsttype==1)
            {
                lst=v1.back();
                v1.pop_back();
                insert(lst,row);
                row--;
            }
            insert(lst,row);
            insert(i,row);
            row--;
            lsttype=3;
            lst=i;
        }
    }
    while(v1.size())
    {
        int x=v1.back();
        v1.pop_back();
        insert(x,row);
        row--;
    }
    print();
    return 0;
}