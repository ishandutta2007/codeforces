#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<array<int,2>,int> m;
    vector<int> one(n);
    vector<int> two(n);
    for(int i=0;i<n;i++) cin >> one[i];
    for(int i=0;i<n;i++) cin >> two[i];
    int res=0;
    for(int i=0;i<n;i++)
    {
        auto [a,b]=make_pair(one[i],two[i]);
        if(a==0)
        {
            if(b==0) res++;
            continue;
        }
        if(b==0) m[{0,1}]++;
        else
        {
            int s=-1;
            if(a<0) s*=(-1);
            if(b<0) s*=(-1);
            a=abs(a);
            b=abs(b);
            m[{s*b/gcd(a,b),a/gcd(a,b)}]++;
        }
    }
    int x=0;
    for(auto [a,b]:m) x=max(x,b);
    cout << res+x << "\n";
    return 0;
}