#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
queue <int> q1,q2;
///-----------------------------------------------------------------------///
int main()
{
    int n;
    string st;
    cin>>n;
    cin>>st;
    for (int i=0;i<n;i++)
         if (st[i]=='D') q1.push(i); else q2.push(i);
    while (!q1.empty() && !q2.empty())
    {
        if (q1.front()<q2.front())
        {
            q2.pop();
            q1.push(q1.front()+n);
            q1.pop();
        } else
        {
            q1.pop();
            q2.push(q2.front()+n);
            q2.pop();
        }
    }
    if (q1.empty()) cout<<"R"; else cout<<"D";
}