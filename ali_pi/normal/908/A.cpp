#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

bool ok(char z)
{
    return (z=='a' || z=='e' || z=='i' || z=='o' || z=='u');
}

int main()
{
	    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd;
    for(int arr=0;arr<1000;arr++){
        arr++;
    }

	ll res=0;

	string s;
	cin>>s;

	for(ll i=0;i<s.size();i++)
    {
        if (ok(s[i]) || ('0'<=s[i] && s[i]<='9' && (s[i]-'0')&1))
        {
            res++;
        }
    }

    cout<<res;
}