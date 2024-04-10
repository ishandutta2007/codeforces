#include <bits/stdc++.h>
using namespace std;

#define ll long long

int s(int n)
{
    int n1 = n;
    int res = 0;
    while (n) {res+=(n%10); n/=10;}
    return res+n1;
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vector<int> a;
    for (int i = max(0, n-99); i<=n; i++) if (s(i)==n) a.push_back(i);
    cout<<a.size()<<endl;
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<endl;

}