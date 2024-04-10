#include <iostream>
#include <set>
#include <cstdlib>

#define M 100100

using namespace std;

long a[M],b[M],n;
multiset<int> s;
multiset<int>::iterator it;

void read(void){
    cin>>n;
    for (long x,i=1; i<=n; ++i){
        cin>>x;
        a[x]=i;
    }
    for (long i=1; i<=n; ++i)
    cin>>b[i];

    for (long i=1; i<=n; ++i)
    s.insert(i-a[b[i]]);
}

void kill(void){
    for (long x,i=0; i<n;){
        it=s.lower_bound(i);
        x=M;
        if (it!=s.end())
        x=min(x,(*it-i));
        if (it!=s.begin()){
            it--;
            x=min(x,(i-*it));
        }
        cout<<x<<"\n";
        i++;
        s.erase(s.find(i-a[b[i]]));
        s.insert(i+n-a[b[i]]);

    }
}

int main()
{
    read();
    kill();
    return 0;
}