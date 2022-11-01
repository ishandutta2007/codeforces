#include <bits/stdc++.h>

using namespace std;

int n;
string s,t;
string res;

void solve()
{
    vector<char> v={'a','b','c'};
    do
    {
        string a,b;
        a+=v[0]; a+=v[1];
        b+=v[1]; b+=v[2];
        if(a==s||a==t||b==s||b==t) continue;
        for(int o=0;o<3;o++) for(int i=0;i<n;i++) res+=v[o];
        break;

    } while(next_permutation(v.begin(),v.end()));
}

void mix()
{
    string a="abc";
    string b="acb";
    string one[3]={"ab","bc","ca"};
    bool ok=1;
    for(int i=0;i<3;i++) if(one[i]==s||one[i]==t) ok=0;
    for(int i=0;i<n;i++)
    {
        if(ok) res+=a;
        else res+=b;
    }
}

int main()
{
	cin >> n;
	cin >> s >> t;
	cout << "YES\n";
	if(s[0]==s[1]||t[0]==t[1]) mix();
	else solve();
	cout << res << endl;
	return 0;
}