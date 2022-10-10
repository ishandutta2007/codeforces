/************************************************************************************************************************************************************************************
  *                                                                                                                                                                                  *
   *                                                                                                                                                                                  *
    *  ****************    **************    *               *    ****************    *           *    ****************    *              *    ****************    ****************    *
     *  *              *    *            *    *               *    *              *    **          *    *                   *              *    *              *                   *    *
      *  *              *    *            *    *               *    *              *    * *         *    *                   *              *    *              *                   *    *
       *  *              *    *            *    *               *    *              *    *  *        *    *                   *              *    *              *                   *    *
        *  *              *    *            *    *               *    *              *    *   *       *    *                   *              *    *              *                   *    *
         *  *              *    *            *    *               *    *              *    *    *      *    *                   *              *    *              *                   *    *
          *  ****************    **************    *****************    ****************    *     *     *    *                   ****************    *              *    ****************    *
           *  *              *    *  *                      *            *              *    *      *    *    *                                  *    *              *                   *    *
            *  *              *    *    *                    *            *              *    *       *   *    *                                  *    *              *                   *    *
             *  *              *    *      *                  *            *              *    *        *  *    *                                  *    *              *                   *    *
              *  *              *    *        *                *            *              *    *         * *    *                                  *    *              *                   *    *
               *  *              *    *          *              *            *              *    *          **    *                                  *    *              *                   *    *
                *  *              *    *            *            *            *              *    *           *    ****************                   *    ****************    ****************    *
                 *                                                                                                                                                                                  *
                  *                                                                                                                                                                                  *
                   ************************************************************************************************************************************************************************************/
/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  Author - Aryan Choudhary (@aryanc403)
 
  const short DEBUG { 0 };
  #define debug(x) if (DEBUG) cout << #x << " = " << x << '\n'
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

//const lli [3] ={ 999119999L,1000000007L,1000992299L};
//const lli [3] ={ 97L,101L,103L};
//const lli  = chrono::high_resolution_clock::now().time_since_epoch().count();
clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class CMP
{
public:
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return ! ( a <= b );
    }
};

void add( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,1));
    else                    jt->Y++;
}

void del( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y==1)            m.erase(jt);
    else                    jt->Y--;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,m,j,k,in,cnt,l,r;
    vi :: iterator it;
    string s;
    bool A,a,no;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
cin>>T;while(T--)
{

    cin>>s;
    A=a=no=false;
    n=s.size();
    fo(i,n)
    {
        if('A'<=s[i]&&s[i]<='Z')
            A|=true;
        else if('a'<=s[i]&&s[i]<='z')
            a|=true;
        else
            no|=true;
    }
    
    if(A&&a&&no)
    {
        true;
    }
    else if(A&&a)
    {
        a=A=false;
        fo(i,n)
        {
            if('a'<=s[i]&&s[i]<='z')
            {
                if(a)
                {
                    s[i]='0';
                    break;
                }
                a|=true;
            }
            else
            {
                if(A)
                {
                    s[i]='0';
                    break;
                }
                A|=true;
            }
        }
    }
    else if(a&&no)
    {
        a=no=false;
        fo(i,n)
        {
            if('a'<=s[i]&&s[i]<='z')
            {
                if(a)
                {
                    s[i]='A';
                    break;
                }
                a|=true;
            }
            else
            {
                if(no)
                {
                    s[i]='A';
                    break;
                }
                no|=true;
            }
        }
    }
    else if(A&&no)
    {
        A=no=false;
        fo(i,n)
        {
            if('A'<=s[i]&&s[i]<='Z')
            {
                if(A)
                {
                    s[i]='a';
                    break;
                }
                A|=true;
            }
            else
            {
                if(no)
                {
                    s[i]='a';
                    break;
                }
                no|=true;
            }
        }
    }
    else if(a)
    {
        s[0]='A';
        s[1]='0';
    }
    else if(A)
    {
        s[0]='a';
        s[1]='0';
    }
    else if(no)
    {
        s[0]='a';
        s[1]='A';
    }
    cout<<s<<endl;

}   aryanc403();
    return 0;
}