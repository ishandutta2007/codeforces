#include <iostream>
#include <vector>
#include <algorithm>

#define s second
#define f first
#define mp make_pair
#define pb push_back
#define L 30
#define long long long

using namespace std;

long n,d,den;
double s=0;
vector<long> l(L,0),r(L,0);
vector<pair<long,long> > g[L];



void read(void){
    long ind;
    char ch;
    cin>>n;

    for (long i=1; i<=n; ++i){
        cin>>ch;
        ind=ch-'A';
        l[ind]+=i;
        g[ind].pb(mp(i,0));
    }

    for (long i=1; i<=n; ++i){
        cin>>ch;
        ind=ch-'A';
        r[ind]+=i;
        g[ind].pb(mp(i,1));
    }
}

long calc(long t){
    long sl=0,sr=0,c=g[t].size(),ans=0;
    sort(g[t].begin(),g[t].end());
    for (long i=0; i<c; ++i)
    if (!g[t][i].s){
        ans+=sr;
        sl+=g[t][i].f;
    }
    else{
        ans+=sl;
        sr+=g[t][i].f;
    }

    return ans;

}

int main()
{
    read();

    cout.precision(20);


    for (long i=0; i<26; ++i)
    s+=calc(i);

    d=n*(n+1)*(2*n+1)/6;


    s=s*6/n/(2*n+1);

    for (long i=0; i<26; ++i)
    s-=((double)l[i]*r[i]/d);

    cout<<s;



    return 0;
}