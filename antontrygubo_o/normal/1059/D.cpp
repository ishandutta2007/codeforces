#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
int n;
vector<pair<ld, ld> > a;

bool check (ld r)
{
    ld d = 2*r;
    ld minr = 100000000; 
    ld maxl = -100000000;
    for (int i = 0; i<n; i++)
    {
        if (a[i].second>d) return 0;
        ld kek = sqrt(a[i].second)*sqrt(d-a[i].second);
        minr = min(minr, a[i].first+kek);
        maxl = max(maxl, a[i].first-kek);
    }
    return (minr+0.00000001>maxl);
}

int main()
{
    cin>>n;
    a.resize(n);
    bool checkneg = false;
    bool checkpos = false;
    for (int i = 0; i<n; i++)
    {
        cin>>a[i].first>>a[i].second;
        if (a[i].second>0) checkpos = true;
        else checkneg = true;
    }
    
    ld maxx = 0;
    
    
    if (checkneg&&checkpos) {cout<<-1; return 0;}
    
    if (checkneg)
    {
        for (int i = 0; i<n; i++) a[i].second = -a[i].second;
    }

    ld l = 0;
    ld r = 1;
    while (!check(r)) r*=2;
    while (r-l>r/100000000)
    {
        ld current = (l+r)/2;
        if (check(current)) r = current;
        else l = current;
    }
    cout<<setprecision(30)<<(l+r)/2;
    
}