#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

#define M 222

multiset<int> s,t,a,b;
int n,f[M],k;

void read(void){
    cin>>n>>k;
    for (int i=0; i<n; ++i)
    cin>>f[i];
}

int get(void){
    int sum=0;
    a=s;
    b=t;
    for (multiset<int>::iterator it = a.begin(); it!=a.end(); ++it)
        sum+=*it;
    for (int i=0; i<k; ++i){
        if (b.empty() || a.empty())
            break;
        int y=*b.rbegin();
        int x=*a.begin();
        if (y>x){
            sum+=(y-x);
            a.erase(a.find(x));
            b.erase(b.find(y));
        }
    }
    return sum;
}

void kill(void){
    int ans=f[0];
    for (int i=0; i<n; ++i){
        s.clear();
        t.clear();
        
        for (int j=0; j<i; ++j)
            t.insert(f[j]);
            
        for (int j=i; j<n; ++j)
            s.insert(f[j]);
            
        for (int j=n-1; j>i; --j){
            ans=max(ans,get());
            s.erase(s.find(f[j]));
            t.insert(f[j]);
        }
        
    }
    
    cout<<ans<<"\n";
}

int main()
{
#ifdef TROLL
    freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();
    
    return 0;
}