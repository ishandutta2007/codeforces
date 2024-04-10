#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

VI manacher(const string& s)
{
    VI p(s.size());
    int id = 0;
    int mx = 0;
    for (int i = 1; i < s.size(); ++i) 
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (i >= p[i] && i + p[i] < s.size() && s[i + p[i]] == s[i - p[i]]) ++p[i];
        if (mx < i + p[i]) 
        {
            mx = i + p[i];
            id = i;
        }
    }
    return p;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
    int testcase;
    for (cin>>testcase;testcase>0;testcase--)
	{
        string s;
        cin>>s;
        int p=0;
        for (;(p+1)*2<=LENGTH(s) && s[p]==s[LENGTH(s)-1-p];p++);
        string t=s.substr(p,LENGTH(s)-p*2);
        string ret="";
        int n=LENGTH(t);
        if (n>0)
        {
            string t2="#.";
            REP(i,n)
            {
                if (i>0) t2+=".";
                t2+=t[i];
            }
            t2+=".";
            VI p=manacher(t2);
            int max_l=0;
            int max_s;
            REP(i,n)
            {
                int l=p[i*2+2]-1;
                if (l>max_l && (i-l/2==0 || i+l/2==n-1))
                    max_l=l,max_s=i-l/2;
            }
            REP(i,n-1)
            {
                int l=p[i*2+3]-1;
                if (l>max_l && (i-l/2+1==0 || i+l/2==n-1))
                    max_l=l,max_s=i-l/2+1;
            }
            ret=t.substr(max_s,max_l);
        }
        cout<<s.substr(0,p)+ret+s.substr(LENGTH(s)-p)<<endl;
	}
	return 0;
}