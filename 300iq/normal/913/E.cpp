#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

vector <string> ans = {"!x&x","x&y&z","!z&x&y","x&y","!y&x&z","x&z","!y&x&z|!z&x&y","(y|z)&x","!y&!z&x","!y&!z&x|x&y&z","!z&x","!z&x|x&y","!y&x","!y&x|x&z","!(y&z)&x","x","!x&y&z","y&z","!x&y&z|!z&x&y","(x|z)&y","!x&y&z|!y&x&z","(x|y)&z","!x&y&z|!y&x&z|!z&x&y","(x|y)&z|x&y","!x&y&z|!y&!z&x","!y&!z&x|y&z","!x&y&z|!z&x","!z&x|y&z","!x&y&z|!y&x","!y&x|y&z","!(y&z)&x|!x&y&z","x|y&z","!x&!z&y","!x&!z&y|x&y&z","!z&y","!z&y|x&y","!x&!z&y|!y&x&z","!x&!z&y|x&z","!y&x&z|!z&y","!z&y|x&z","!(!x&!y|x&y|z)","!(!x&!y|x&y|z)|x&y&z","!z&(x|y)","!z&(x|y)|x&y","!x&!z&y|!y&x","!x&!z&y|!y&x|x&z","!y&x|!z&y","!z&y|x","!x&y","!x&y|y&z","!(x&z)&y","y","!x&y|!y&x&z","!x&y|x&z","!(x&z)&y|!y&x&z","x&z|y","!x&y|!y&!z&x","!x&y|!y&!z&x|y&z","!x&y|!z&x","!z&x|y","!x&y|!y&x","!x&y|!y&x|x&z","!(x&z)&y|!y&x","x|y","!x&!y&z","!x&!y&z|x&y&z","!x&!y&z|!z&x&y","!x&!y&z|x&y","!y&z","!y&z|x&z","!y&z|!z&x&y","!y&z|x&y","!(!x&!z|x&z|y)","!(!x&!z|x&z|y)|x&y&z","!x&!y&z|!z&x","!x&!y&z|!z&x|x&y","!y&(x|z)","!y&(x|z)|x&z","!y&z|!z&x","!y&z|x","!x&z","!x&z|y&z","!x&z|!z&x&y","!x&z|x&y","!(x&y)&z","z","!(x&y)&z|!z&x&y","x&y|z","!x&z|!y&!z&x","!x&z|!y&!z&x|y&z","!x&z|!z&x","!x&z|!z&x|x&y","!x&z|!y&x","!y&x|z","!(x&y)&z|!z&x","x|z","!(!y&!z|x|y&z)","!(!y&!z|x|y&z)|x&y&z","!x&!y&z|!z&y","!x&!y&z|!z&y|x&y","!x&!z&y|!y&z","!x&!z&y|!y&z|x&z","!y&z|!z&y","!y&z|!z&y|x&y","!(!x&!y|x&y|z)|!x&!y&z","!(!x&!y|x&y|z)|!x&!y&z|x&y&z","!x&!y&z|!z&(x|y)","!x&!y&z|!z&(x|y)|x&y","!x&!z&y|!y&(x|z)","!x&!z&y|!y&(x|z)|x&z","!y&(x|z)|!z&y","!y&z|!z&y|x","!x&(y|z)","!x&(y|z)|y&z","!x&z|!z&y","!x&z|y","!x&y|!y&z","!x&y|z","!(x&y)&z|!z&y","y|z","!x&(y|z)|!y&!z&x","!x&(y|z)|!y&!z&x|y&z","!x&(y|z)|!z&x","!x&z|!z&x|y","!x&(y|z)|!y&x","!x&y|!y&x|z","!x&y|!y&z|!z&x","x|y|z","!(x|y|z)","!(x|y|z)|x&y&z","!(!x&y|!y&x|z)","!(x|y|z)|x&y","!(!x&z|!z&x|y)","!(x|y|z)|x&z","!(!x&y|!y&x|z)|!y&x&z","!(x|y|z)|(y|z)&x","!y&!z","!y&!z|x&y&z","!(!x&y|z)","!y&!z|x&y","!(!x&z|y)","!y&!z|x&z","!(!x&y|z)|!y&x","!y&!z|x","!(!y&z|!z&y|x)","!(x|y|z)|y&z","!(!x&y|!y&x|z)|!x&y&z","!(x|y|z)|(x|z)&y","!(!x&z|!z&x|y)|!x&y&z","!(x|y|z)|(x|y)&z","!(!x&y|!y&x|z)|!x&y&z|!y&x&z","!(x|y|z)|(x|y)&z|x&y","!x&y&z|!y&!z","!y&!z|y&z","!(!x&y|z)|!x&y&z","!(!x&y|z)|y&z","!(!x&z|y)|!x&y&z","!(!x&z|y)|y&z","!(!x&y|z)|!x&y&z|!y&x","!y&!z|x|y&z","!x&!z","!x&!z|x&y&z","!(!y&x|z)","!x&!z|x&y","!x&!z|!y&x&z","!x&!z|x&z","!(!y&x|z)|!y&x&z","!(!y&x|z)|x&z","!(x&y|z)","!(x&y|z)|x&y&z","!z","!z|x&y","!x&!z|!y&x","!(x&y|z)|x&z","!y&x|!z","!z|x","!(!y&z|x)","!x&!z|y&z","!(!y&x|z)|!x&y","!x&!z|y","!(!y&z|x)|!y&x&z","!(!y&z|x)|x&z","!(!y&x|z)|!x&y|!y&x&z","!x&!z|x&z|y","!x&y|!y&!z","!(x&y|z)|y&z","!x&y|!z","!z|y","!(!x&!y&z|x&y)","!x&!z|!y&x|y&z","!x&y|!y&x|!z","!z|x|y","!x&!y","!x&!y|x&y&z","!x&!y|!z&x&y","!x&!y|x&y","!(!z&x|y)","!x&!y|x&z","!(!z&x|y)|!z&x&y","!(!z&x|y)|x&y","!(x&z|y)","!(x&z|y)|x&y&z","!x&!y|!z&x","!(x&z|y)|x&y","!y","!y|x&z","!y|!z&x","!y|x","!(!z&y|x)","!x&!y|y&z","!(!z&y|x)|!z&x&y","!(!z&y|x)|x&y","!(!z&x|y)|!x&z","!x&!y|z","!(!z&x|y)|!x&z|!z&x&y","!x&!y|x&y|z","!x&z|!y&!z","!(x&z|y)|y&z","!(!x&!z&y|x&z)","!x&!y|!z&x|y&z","!x&z|!y","!y|z","!x&z|!y|!z&x","!y|x|z","!(x|y&z)","!(x|y&z)|x&y&z","!x&!y|!z&y","!(x|y&z)|x&y","!x&!z|!y&z","!(x|y&z)|x&z","!(!y&!z&x|y&z)","!x&!y|!z&y|x&z","!((x|y)&z|x&y)","!((x|y)&z|x&y)|x&y&z","!x&!y|!z","!x&!y|!z|x&y","!x&!z|!y","!x&!z|!y|x&z","!y|!z","!y|!z|x","!x","!x|y&z","!x|!z&y","!x|y","!x|!y&z","!x|z","!x|!y&z|!z&y","!x|y|z","!x|!y&!z","!x|!y&!z|y&z","!x|!z","!x|!z|y","!x|!y","!x|!y|z","!(x&y&z)","!x|x",};

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int ret = 0;
        for (int i = 0; i < 8; i++)
        {
            char c;
            scanf(" %c", &c);
            ret = ret * 2 + c - '0';
        }
        puts(ans[ret].c_str());
    }
}