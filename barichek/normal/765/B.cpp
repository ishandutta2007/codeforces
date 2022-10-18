#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int had[ar];
bool easy_had[ar];

void easy_check(string s)
{
    for (auto i:s)
        if (!easy_had[i])
        {
            easy_had[i]=true;
            for (int j='a';j<i;j++)
                if (!easy_had[j])
                    exit(!(cout<<"NO\n"));
        }
}

main()
{
    string s;
    cin>>s;
    for (auto i:s)
        had[i]++;
    easy_check(s);
    int cur=0;
    for (int i='a';i<='z';i++)
    {
        cur+=had[i];
        if (cur==s.length()) return cout<<"YES\n", 0;
        if (had[i]==0) return cout<<"NO\n", 0;
    }
    cout<<"NO\n";
}