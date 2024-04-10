//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

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

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 1000+10, inf = 1000111222;

char a[max_n][max_n];

void ___main___()
{
    int n;
    cin>>n;
    if (n==2){
        cout<<-1<<"\n";
        return;
    }
    int ans=1;
    while (ans*ans<n){
        ans++;
    }
    int kek=ans;
    if (kek*kek>n){
        kek--;
    }

    bool flag=0;
    if (ans*ans==n+2){
        ans++;
        kek=ans-1;
        flag=1;
    }

    for (int i=0;i<max_n;i++){
        for (int j=0;j<max_n;j++){
            a[i][j]='.';
        }
    }
    for (int i=0;i<kek;i++){
        for (int j=0;j<kek;j++){
            a[i][j]='o';
            n--;
        }
    }
    if (flag){
        a[kek-1][kek-1]='.';
        a[kek-2][kek-1]='.';
        a[kek-2][kek-2]='.';
        a[kek-1][kek-2]='.';
        a[0][ans-1]='o';
        a[ans-1][0]='o';
    }
    else{
        assert(n>=0);
        if (n%2==1){
            a[kek-1][kek-1]='.';
            n++;
        }
        for (int j=0;j<n/2;j++){
            a[kek][j]='o';
        }
        for (int i=0;i<n/2;i++){
            a[i][kek]='o';
        }
    }
    cout<<ans<<"\n";
    for (int i=0;i<ans;i++){
        for (int j=0;j<ans;j++){
            cout<<a[ans-i-1][j];
        }
        cout<<"\n";
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ___main___();

    exit(0);
}