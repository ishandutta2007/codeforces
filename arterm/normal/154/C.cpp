#include <iostream>
#include <vector>
#include <algorithm>

#define long long long
#define pi 41
#define M 1000111
#define pb push_back
#define s second
#define f first
#define mp make_pair

using namespace std;

long n,m,p[M],ans=0,ha[M];
vector<long> g[M];
pair< pair<long,long>, long> t[M];
pair<long, long> e[M];

void pre(void){
    p[0]=1;
    for (long i=1; i<M; ++i)
    p[i]=p[i-1]*pi;
}


void read(void){
    long a,b;
    cin>>n>>m;
    for (long i=0; i<m; ++i){
        cin>>a>>b;
        a--;
        b--;
        ha[a]+=p[b];
        ha[b]+=p[a];
        e[i]=mp(a,b);
    }

    for (long i=0; i<m; ++i)
    if (ha[e[i].f]+p[e[i].f]==ha[e[i].s]+p[e[i].s])
    ans++;

    sort(ha,ha+n);
    for (long i=0,j; i<n; ){
        j=i;
        while(j<n && ha[i]==ha[j])
        ++j;
        ans+=((j-i)*(j-i-1)/2);
        i=j;
    }


}

int main()
{
    pre();
    read();
    cout<<ans;
    return 0;
}