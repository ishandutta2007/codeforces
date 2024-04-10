#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool check(char c)
{
    return(c=='i' || c=='o' || c=='a' || c=='u' || c=='e' || c=='y');
}

signed main()
{
    string st;
    cin>>st>>st;

    string res="";
    res+='!';

    for (auto i:st)
    {
        if (check(i) && check(res.back())); else
            res+=i;
    }
    reverse(res.begin(),res.end());
    res.pop_back();
    reverse(res.begin(),res.end());
    cout<<res;
}
/*

*/