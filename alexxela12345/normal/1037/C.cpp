// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

int main() 
{
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s1[i] != s2[i] && s1[i] == s2[i + 1] && s1[i + 1] == s2[i]) {
			auto tmp = s1[i];
			s1[i] = s1[i + 1];
			s1[i + 1] = tmp;
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}