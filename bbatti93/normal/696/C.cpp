#include <bits/stdc++.h>

using namespace std;

long long n, ki,a,ki2;
const long long M=1000000007;
bool paros=false;

long long hatv(long long a, long long b) {
    long long ki=1, sz=a;
    while(b>0) {
        if(b%2) ki=(ki*sz)%M;
        sz=sz*sz%M;
        b/=2;
    }
    return ki;
}

int main()
{
    cin >> n;
    ki=2;
    for(int i=0;i<n;i++) {
        cin >> a;
        ki=hatv(ki,a);
        if(a%2==0) paros=true;
    }
    while(ki%2) ki+=M;
    ki=ki/2;
    ki2=ki+1;
    if(!paros) ki2-=2;
    while(ki2%3) ki2+=M;
    ki2/=3;
    ki2=ki2%M;
    ki=ki%M;
    cout << ki2 << "/" << ki << endl;
    return 0;
}