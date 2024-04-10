#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
void rng_shuffle(auto &v) {shuffle(v.begin(),v.end(),gen);}

char query(int a,int b,int c,int d)
{
    cout << "? " << b-a+1 << " " << d-c+1 << "\n";
    for(int i=a;i<=b;i++) cout << i << " \n"[i==b];
    for(int i=c;i<=d;i++) cout << i << " \n"[i==d];
    cout.flush();
    string s;
    cin >> s;
    if(s[0]=='W') exit(0);
    return s[0];
}

void answer(int a)
{
    cout << "! " << a << "\n";
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> v;
        for(int i=2;i<=n;i++) v.push_back(i);
        rng_shuffle(v);
        bool gift=0;
        for(int i=0;i<min(n-1,30);i++)
        {
            if(query(1,1,v[i],v[i])=='S') gift=1;
        }
        if(gift==1)
        {
            answer(1);
            continue;
        }
        int x=1;
        for(;2*x<=n;x*=2) if(query(1,x,x+1,2*x)=='F') break;
        int l=x;
        int r=min(2*x,n);
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(query(1,m-x,x+1,m)=='F') r=m;
            else l=m;
        }
        answer(r);
    }
    return 0;
}