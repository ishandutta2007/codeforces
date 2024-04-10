#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;


int main()
{
ios_base::sync_with_stdio(false);
int n, k;
cin>>n>>k;
vector<int> a(n+1);
for (int i = 0; i<n; i++) cin>>a[i];
a[n] = 10000000;
sort(a.begin(), a.end());
int res = 0;
for (int i = 0; i<n; i++)
{
    int counter = 1;
    while (i<n&&a[i]==a[i+1]) {counter++; i++;}
    if (i==n||a[i]+k<a[i+1]) res+=counter;
}

cout<<res;

}