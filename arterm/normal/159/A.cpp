#include <iostream>
#include <string>
#include <set>

#define N 3000
#define mp make_pair
#define f first
#define s second

using namespace std;

pair<string,string> u[N];
set<pair<string,string> > s;
long t[N];

int main()
{
    string s1,s2;
    long n,d;
    cin>>n>>d;
    for (long i=0; i<n; ++i){
        cin>>s1>>s2>>t[i];
        u[i]=mp(s1,s2);
    }
    for (long i=0; i<n; ++i)
    for (long j=i+1; j<n && t[j]-t[i]<=d; ++j)
    if (u[i].f==u[j].s && u[i].s==u[j].f && t[j]-t[i]>0)
    s.insert(mp(max(u[i].f,u[i].s),min(u[i].f,u[i].s)));
    cout<<distance(s.begin(),s.end())<<endl;
    for (set<pair<string,string> >::iterator i=s.begin(); i!=s.end(); ++i)
    cout<<i->f<<" "<<i->s<<"\n";

    return 0;
}