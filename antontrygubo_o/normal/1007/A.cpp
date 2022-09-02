#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;


int main()
{
ios_base::sync_with_stdio(false);

int n;
cin>>n;
vector<int> a(n);
vector<int> b(n);
for (int i = 0; i<n; i++) {cin>>a[i]; b[i] = a[i];}
sort(a.begin(), a.end());
sort(b.begin(), b.end());
int counter = 0;
int idx = 0;
for (int i = 0; i<n; i++)
{
    while (idx<n&&b[idx]<=a[i]) idx++;
    if (idx<n&&a[i]<b[idx]) {idx++; counter++;}
}
cout<<counter;

}