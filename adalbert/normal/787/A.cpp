//#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <utility>
#include <time.h>
#include <complex>
#include <unordered_set>
#include <unordered_map>
#define PI 3.141592653
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define INF 1e18+1
#define fi first
#define se second
#define ld long double
#pragma GCC optimize("O3")
#define ull unsigned long long

using namespace std;

ll md = 1e9 + 7;
ll md2 = 1e9 + 9;

//-----PROGRAM START-----//

int a,b,c,d;

int main()
{
    //freopen("substr.dat","r",stdin);
    //freopen("substr.sol","w",stdout);
    
    cin >> a >> b >> c >> d;

    for (int i = max(b,d); i<= 1005001 ;i++)
        if ((i-b)%a==0 && (i-d)%c==0)
        {
            return cout << i,0;
        }
    
    cout << -1;
    
    return 0;
}