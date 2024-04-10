#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;

vector<int> f(string s)
{
    vector<int> res(3, 1);
    int n = s.length();
    int tempo = 0;
    int tempc = 0;
    for (int i = 0; i<n; i++)
    {
        if (s[i]=='(') tempo++;
        else tempc++;
        if (tempo<tempc) res[1] = 0;
    }
    res[0] = tempo-tempc;
    tempo = 0;
    tempc = 0;
    for (int i = n-1; i>=0; i--) 
    {
        if (s[i]=='(') tempo ++;
        else tempc++;
        if (tempc<tempo) res[2] = 0;
    }
    return res;
}

int main()
{
ios_base::sync_with_stdio(false);
int n;
cin>>n;
vector<ll> start(300001, 0);
vector<ll> ends(300001, 0);
for (int i = 0; i<n; i++)
{
    string s;
    cin>>s;
    vector<int> temp = f(s);
    if (temp[0]>=0&&temp[1]==1) start[temp[0]]++;
    if (temp[0]<=0&&temp[2]==1) ends[-temp[0]]++;
}
    ll result = 0;
    for (int i = 0; i<300001; i++) result+=start[i]*ends[i];
    cout<<result;
}