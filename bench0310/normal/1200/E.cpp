#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
const long long p=101;
const long long mod=1000000007;
long long e[N];

void ini()
{
    e[0]=1;
    for(int i=1;i<N;i++) e[i]=(e[i-1]*p)%mod;
}

long long val(char c)
{
    if('a'<=c&&c<='z') return (c-'a');
    else if('A'<=c&&c<='Z') return (c-'A'+26);
    else return (c-'0'+52);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ini();
	int n;
	cin >> n;
	string s;
	cin >> s;
	while(--n)
    {
        string t;
        cin >> t;
        int idx=-1;
        long long one=0,two=0;
        for(int i=0;i<(int)min(t.size(),s.size());i++)
        {
            one=(one+(e[i]*val(s[s.size()-1-i])))%mod;
            two=(two*p)%mod;
            two=(two+val(t[i]))%mod;
            if(one==two) idx=i;
        }
        for(int i=idx+1;i<(int)t.size();i++) s+=t[i];
    }
    cout << s << endl;
	return 0;
}