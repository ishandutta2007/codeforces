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

const ii mod = mp(1000000007L,1000992299L);
const ii bas = mp(101L,103L);
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

    lli T,n,i,j,k,in,cnt,l,r;
    vector<lli> a;
    // vector< vi > has,rHas;
    map<lli,lli> :: iterator it;
    // map<ii,lli> m;
    map<lli,lli> mo,me;
    // ii po[1000005];
    string s;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

// void addHash(vi &a,vi &b,string &s)
// {
//     lli l=s.size();
//     a.reserve(l+1);
//     b.reserve(l+1);
//     ii ans;
//     for(lli i=0;i<l;++i)
//     {
//         ans.X=a[i].X*bas.X;ans.X%=mod.X;
//         ans.X+=s[i];ans.X%=mod.X;
        
//         ans.Y=a[i].Y*bas.Y;ans.Y%=mod.Y;
//         ans.Y+=s[i];ans.Y%=mod.Y;
//         a.pb(ans);
//     }
    
//     for(lli i=l-1;i>=0;--i)
//     {
//         ans.X=b[l-1-i].X*bas.X;ans.X%=mod.X;
//         ans.X+=s[i];ans.X%=mod.X;
        
//         ans.Y=b[l-1-i].Y*bas.Y;ans.Y%=mod.Y;
//         ans.Y+=s[i];ans.Y%=mod.Y;
//         b.pb(ans);
//     }
//     add(m,b[l]);
// }

// ii revhash(string &s)
// {
//     lli l=s.size();
//     ii ans=mp(0,0);
//     for(lli i=l-1;i>=0;--i)
//     {
//         ans.X*=bas.X;ans.X%=mod.X;
//         ans.X+=s[i];ans.X%=mod.X;
        
//         ans.Y*=bas.Y;ans.Y%=mod.Y;
//         ans.Y+=s[i];ans.Y%=mod.Y;
//     }
//     return ans;
// }

// bool isPal(lli i,lli j)
// {
//     ii fr;
//     fr=mp(0,0);
    
//     fr.X=has[i][l].X-(has[i][j].X*po[l-j].X)%mod.X;
//     fr.X+=mod.X;fr.X%=mod.X;

//     fr.Y=has[i][l].Y-(has[i][j].Y*po[l-j].Y)%mod.Y;
//     fr.Y+=mod.Y;fr.Y%=mod.Y;

//     return fr==rhas[i][l-j];
// }

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
    // po[0].X=po[0].Y=1;
    // for(i=1;i<1000001;++i)
    // {
    //     po[i].X=po[i-1].X*bas.X;po[i].X%=mod.X;
    //     po[i].Y=po[i-1].Y*bas.Y;po[i].Y%=mod.Y;
    // }
    
// cin>>T;while(T--)
{
    // vi st;
    // st.pb(mp(0,0));
    cin>>n;
    // a.clear();a.reserve(n);
    // has.clear();has.reserve(n);
    // rhas.clear();rhas.reserve(n);
    fo(i,n)
    {
        cin>>s;
        lli val=0;
        l=s.size();
        for(j=0;j<l;++j)
            val^=1<<(s[j]-'a');
        if(l%2)
            add(mo,val);
        else
            add(me,val);
        // a.pb(s);
        // has.pb(st);
        // rhas.pb(st);
        // addHash(has[i],rhas[i],s);
    }

    cnt=0;
    for(auto &x:me)
    {
        cnt+=x.Y*(x.Y-1)/2;
        // cout<<x.X<<" "<<x.Y<<endl;
    }
    
    for(auto &x:mo)
    {
        cnt+=x.Y*(x.Y-1)/2;
        for(j=0;j<26;++j)
        {
            it=me.find(x.X^(1<<j));
            if(it!=me.end())
                cnt+=x.Y*(it->Y);
        }
        // cout<<x.X<<" "<<x.Y<<endl;
    }
    
    // fo(i,n)
    // {
    //     l=a[i].size();
    //     it=m.find(has[i][l]);
    //     if(it!=m.end())
    //         cnt+=it->Y;
    //     for(j=1;j<l;++j)
    //     {
    //         if(isPal(i,j))
    //         {
    //             it=m.find(has[i][j-1]);
    //             if(it!=m.end())
    //             {
    //                 cnt+=it->Y;
    //             }
    //         }
    //     }
    // }
    cout<<cnt;
}   aryanc403();
    return 0;
}