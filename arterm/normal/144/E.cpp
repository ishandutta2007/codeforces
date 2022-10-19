#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define M 100100
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

long n,m;
pair<pair<long,long>,long> p[M];
vector<long> v;
priority_queue<pair<long,long> > q;

void read(void){
    cin>>n>>m;
    for(long i=1,a,b; i<=m; ++i){
        cin>>a>>b;
        p[i-1]=mp(mp(n+1-b,a),i);
    }
    sort(p,p+m);
}

void greed(void){
    for (long i=1,j=0; i<=n; ++i){
        for (;j<m && p[j].f.f<=i;++j)
        q.push(mp(-p[j].f.s,p[j].s));
        while (!q.empty() && -q.top().f<i)
        q.pop();
        if (!q.empty()){
            v.pb(q.top().s);
            q.pop();
        }
    }
}

int main()
{
    read();
    greed();
    cout<<v.size()<<"\n";
    for (long i=0; i<v.size(); ++i)
    cout<<v[i]<<" ";
    return 0;
}