#include <bits/stdc++.h>
#define pb push_back
#define sz(a) ((int)a.size())
using namespace std;
const int N=1000;
int n,a[N],b[N][N],p[N],s=0;
vector<bool> prime(2000001,true);

int main()
{
 //   ifstream cin("input.txt");

    for(int i=2; i<2000; i++)
        if(prime[i])
            for(int j=i*i; j<2000001; j+=i)
                prime[j]=false;

    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j&&!prime[a[i]+a[j]])
                b[i][j]=1,s++;
//for(int i=0; i<n; i++) cout<<a[i]<<' ';cout<<endl<<endl;
//for(int i=0; i<n; i++,cout<<endl) for(int j=0; j<n; j++) cout<<b[i][j]<<' ';return 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(b[i][j])
                p[i]++;

    list<int> pq;
    for(int i=0; i<n; i++) pq.pb(i);

    while(s)
    {
        int best=pq.front();
        for(int it : pq) if(p[it]>p[best]) best = it;
        s-=2*p[best];
        for(int j=0; j<n; j++) if(b[best][j]==1) p[j]--;
        for(auto it=pq.begin(); it!=pq.end(); it++)
            if(*it==best) {
                pq.erase(it);
                break;
            }
    }

    cout<<sz(pq)<<endl;
    for(int it : pq)
        cout<<a[it]<<' ';
    return 0;
}