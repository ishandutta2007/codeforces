#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;

int main()
{
    int n;
    cin >> n;
    
    vector<pii> mp1;
    vector<pii> mp2;
    vector<pii> mp3;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            mp1.push_back(make_pair(t,i));
        }
        if(t==2)
        {
            mp2.push_back(make_pair(t,i));
        }
        if(t==3)
        {
            mp3.push_back(make_pair(t,i));
        }
    }
    
    int m_s= min(min(mp1.size(),mp2.size()),mp3.size());
    cout << m_s << endl;
    
    for(int i=0;i<m_s;i++)
    {
        cout << mp1[i].second << " " << mp2[i].second << " " << mp3[i].second << endl;
    }
}