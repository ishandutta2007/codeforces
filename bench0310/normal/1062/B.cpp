#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n==1)
    {
        cout << "1 0\n";
        return 0;
    }
    vector<int> v;
    int res=1;
    for(int i=2;i*i<=n;i++)
    {
        if((n%i)>0) continue;
        v.push_back(0);
        res*=i;
        while((n%i)==0)
        {
            v.back()++;
            n/=i;
        }
    }
    if(n>1)
    {
        res*=n;
        v.push_back(1);
    }
    set<int> s;
    for(int i=0;i<=5;i++) s.insert(1<<i);
    int m=0;
    for(int p:v) m=max(m,*s.lower_bound(p));
    int cnt=0;
    for(int p:v) if(p!=m) cnt=1;
    cnt+=__builtin_ctz(m);
    cout << res << " " << cnt << "\n";
    return 0;
}