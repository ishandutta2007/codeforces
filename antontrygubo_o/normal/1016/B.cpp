#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;

vector<int> prefix_function (string s) {
int n = (int) s.length();
vector<int> pi (n);
for (int i=1; i<n; ++i) {
int j = pi[i-1];
while (j > 0 && s[i] != s[j])
j = pi[j-1];
if (s[i] == s[j]) ++j;
pi[i] = j;
}
return pi;
}

int main()
{
ios_base::sync_with_stdio(false);
int n, m, q;
cin>>n>>m>>q;
string s, t;
cin>>s>>t;
string res = t+"#"+s;

vector<int> my = prefix_function(res);

vector<bool> check(n, 0);
for (int i = 0; i<n; i++) if (my[m+i+1]==m) check[i] = true;
vector<int> sum(n+1, 0);
sum[0] = 0;
for (int i = 0; i<n; i++) sum[i+1] = sum[i]+check[i];
for (int i = 0; i<q; i++)
{
    int a, b;
    cin>>a>>b;
    if (b<a+m-1) cout<<0;
    else cout<<sum[b]-sum[a+m-2];
    cout<<endl;
}



}