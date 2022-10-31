#include <bits/stdc++.h>

using namespace std;

long long n, k, h=1, be, ls;
long long p=0;
map<int, int> m;

int main()
{
    cin >> n >> k;
    for(int i=1;i<k;i++) h*=2;
    m[0]++;
    ls=0;
    for(int i=0;i<n;i++) {
        cin >> be;
        be=be^ls;
        if(be>=h) be=2*h-be-1;
        p+=m[be]/2;
        m[be]++;
        ls=be;
    }
    cout << n*(n+1)/2-p << endl;
    return 0;
}