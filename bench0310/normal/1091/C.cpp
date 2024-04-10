#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    set<long long> s;
    long long d=0;
    while(d*d<=n)
    {
        d++;
        if(n%d) continue;
        s.insert(d*(n/d)*(n/d+1)/2-(n/d)*(d-1));
        if(d*d!=n)
        {
            d=n/d;
            s.insert(d*(n/d)*(n/d+1)/2-(n/d)*(d-1));
            d=n/d;
        }
    }
    for(set<long long>::iterator it=s.begin();it!=s.end();it++) cout << *it << " ";
    cout << endl;
    return 0;
}