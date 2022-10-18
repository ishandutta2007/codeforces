#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif
 
#define ll long long
 
using namespace std;
 
const int N = 2e5 + 1000;
 
bool a[N], b[N];
int dp[N];
 
int n, m, t;
 
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> t;
 
    for(int e=0;e<t;e++) {
        cin >> n;
        char c;
        for(int i=0;i<n;i++) {
            cin >> c;
            a[i] = (c == '1');
        }
        for(int i=0;i<n;i++) {
            cin >> c;
            b[i] = (c == '1');
        }
 
        b[n] = false;
        a[n] = false;
 
 
        int best = 0;
        for(int i=0;i<n;i++) {
            if(i>0 && b[i] && a[i-1]) {
                b[i] = false;
                a[i-1]=false;
                best++;
            }
            if (!a[i] && b[i]) {
                b[i] = false;
                b[i]=false;
                best++;
            }
            if (a[i + 1] && b[i]) {
                b[i] = a[i + 1] = false;
                best++;
            }
        }
 
 
        cout << best << "\n";
    }
 
}