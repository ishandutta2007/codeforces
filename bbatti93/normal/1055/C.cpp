#include <bits/stdc++.h>

using namespace std;

long long n;

long long lnko(long long a, long long b) {
    if(b==0) return a;
    return lnko(b,a%b);
}

long long la, ra, ta, lb, rb, tb, t, ki, ki2, ha, hb;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    t=lnko(ta, tb);
    ha=ra-la;
    hb=rb-lb;
    la=la%t;
    lb=lb%t;
    ki=0;
    ki2=min(la+ha,lb+hb)-max(la,lb)+1;
    if(ki2>ki) ki=ki2;
    la+=t;
    ki2=min(la+ha,lb+hb)-max(la,lb)+1;
    if(ki2>ki) ki=ki2;
    la-=t;
    lb+=t;
    ki2=min(la+ha,lb+hb)-max(la,lb)+1;
    if(ki2>ki) ki=ki2;
    cout << ki << endl;
    return 0;
}