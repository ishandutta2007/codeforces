#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;


int main()
{
ios_base::sync_with_stdio(false);
ll n, m, a, b;
cin>>n>>m>>a>>b;
ll t = n%m;
if (t==0) {cout<<0; return 0;}
ll t1 = m-t;
cout<<min(t1*a, t*b);

}