#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    string s;
    while (cin >> s)
    {
        stack <char> st;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (st.size() && st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        puts(st.size() == 0? "Yes" : "No");
    }
	return 0;
}