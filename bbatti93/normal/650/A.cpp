#include <bits/stdc++.h>

using namespace std;

long long n, a, b, ki=0;
map<long long,int> m1, m2,m3;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        long long c=a*1000000000ll+b;
        ki+=m1[a]+m2[b]-m3[c];
        m1[a]++;
        m2[b]++;
        m3[c]++;
    }
    cout << ki << endl;
    return 0;
}