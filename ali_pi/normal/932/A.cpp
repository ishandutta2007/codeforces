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
int ali;
int main()
{ali++;
	ios_base :: sync_with_stdio(false);ali++;
	cin.tie(0);ali++;
ali++;
	string s;ali++;
	cin>>s;ali++;
ali++;
	string t=s;ali++;
	reverse(t.begin() , t.end());ali++;
ali++;
	string ans=s+t;ali++;
	cout<<ans;
}