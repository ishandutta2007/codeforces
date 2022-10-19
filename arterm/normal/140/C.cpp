#include <iostream>
#include <algorithm>
#include <set>

#define M 100100
#define f first
#define s second
#define mp make_pair

using namespace std;

long n,a[M],ans=0;
long p[M][3];
set<pair<long,long> > s;


void read(void){
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i];
    sort(a,a+n);
    for (long j,i=0; i<n; ){
        j=i;
        while (j<n && a[i]==a[j])
        ++j;
        s.insert(mp(j-i,a[i]));
        i=j;
    }
}

void ghos(void){
    set<pair<long,long> >::reverse_iterator it;
    pair<long,long> h[10];
    while (s.size()>=3){
        it=s.rbegin();
        for (long i=0; i<3; ++i){
            h[i]=*it;
            p[ans][i]=h[i].s;
            it++;
        }
        sort(p[ans],p[ans]+3);
        for (long i=0; i<3; ++i){
            s.erase(h[i]);
            h[i].f--;
            if (h[i].f>0)
            s.insert(h[i]);
        }
        ans++;
    }
}

int main()
{
    read();
    ghos();
    cout<<ans<<"\n";
    for (long i=0; i<ans; ++i,cout<<"\n")
    for (long j=2; j>=0; --j)
    cout<<p[i][j]<<" ";
    return 0;
}