// Har Har Mahadev
#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    string s;
    cin >> s;
    // answer would be zero, one, N
    vector<int> cnt(26,0);
    for(auto &j:s)
    	++cnt[j - 'a'];

    int n = sz(s);

    // N
    for(int i=0;i<26;++i)
    {
    	if(cnt[i] == n)
    	{
    		cout << s << "\n";
    		return 0;
    	}
    }

    // zero
    for(int i=0;i<26;++i)
    {
    	if(cnt[i] == 1)
    	{
    		cout << char(i + 'a');
    		--cnt[i];
    		for(int j=0;j<26;++j)
    			while(cnt[j]--)
    				cout << char(j + 'a');
    		cout << "\n";
    		return 0;
    	}
    }

    //one
    string ans = s;
    sort(all(ans),greater<char>());
    
    // N > 2
    string t;
    // min smin and if else
    for(int i=0;i<26;++i)
    {
    	if(cnt[i] == 0)
    		continue;	
    	t += char(i + 'a');
    	string f;
    	for(int j=0;j<cnt[i]-1;++j)
    		f += char(i+'a');
    	for(int j=i+1;j<26;++j)
    	{
    		if(cnt[j] == 0)
    			continue;
    		t += char(j+'a');
    		for(int k=0;k<cnt[j]-1;++k)
    			f += char(j+'a');
    		for(int l=j+1;l<26;++l)
    			for(int k=0;k<cnt[l];++k)
    				f += char(l+'a');
    		break;
    	}
    	// debug(t);
    	// assert(sz(t) == 2);
    	if(t[1] == f.back())
    	{
    		reverse(all(f));
    		t += f;
    	}
    	else
    	{
    		for(int i=0;i<sz(f);++i)
    		{
    			if(f[i] == t[0] && f[i+1] == t[1])
    			{
    				for(int j=i+1;j<sz(f);++j)
    				{
    					if(f[j] == t[1] && f[j+1] != t[1])
    					{
    						swap(f[i+1],f[j+1]);
    						break;
    					}
    				}
    				break;
    			}
    		}
    		t += f;
    	}
    	amin(ans,t);
    	break;
    }
    // cout << ans << "\n";
    // now pehle do barabar
    for(int i=0;i<26;++i)
    {
    	if(cnt[i] <= 1)
    		continue;
    	int rem = cnt[i] - 2;
    	int r_c = n - cnt[i];
    	if(rem > r_c)
    		continue;
    	string t(2,char(i+'a'));
    	// can make
    	string f;
    	for(int j=0;j<26;++j)
    		if(j!=i)
    			for(int k=0;k<cnt[j];++k)
    				f += char(j+'a');
    	reverse(all(f));
    	t += f.back();
    	f.pop_back();
    	--r_c;
    	cnt[i] -= 2;
    	assert(r_c == sz(f));
    	char c = 'a' + i;
    	for(int j=0;j<cnt[i];++j)
    	{
    		int rem = cnt[i] - j;
    		if(r_c >= rem)
    		{
    			if(c > f.back())
    				t += f.back(),f.pop_back(),--r_c,--j;
    			else
    			{
    				t += c;
    				t += f.back();
    				f.pop_back();
    				--r_c;
    			}
    		}
    		else
    		{
    			t += c;
    			if(r_c)
    				t += f.back(),f.pop_back(),--r_c;
    		}
    	}
    	while(r_c--)
    		t += f.back(),f.pop_back();
    	amin(ans,t);
    	break;
    }
    cout << ans << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}