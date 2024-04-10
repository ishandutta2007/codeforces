#include <bits/stdc++.h>

using namespace std;

long long n, ki;
vector<long long> k;


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) {
            k.push_back((2+n-i)*n/i/2);
            long long j=n/i;
            if(i*i!=n) k.push_back((2+n-j)*n/j/2);
        }
    }
    sort(k.begin(),k.end());
    for(int i=0;i<k.size();i++) cout << k[i] << " ";
    cout << endl;
    return 0;
}