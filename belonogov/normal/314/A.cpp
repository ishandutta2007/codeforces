#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

using namespace std;

const int maxn = 2e5 + 10;
const int p = 1e9;

long long a[maxn];

int main(){
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);
    int n;
    long long k, sum = 0, r;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        r = sum - (long long)cnt * a[i] * (n - 1 - i);
       // cerr << r << " " << sum << endl;
        if (r < k)
            printf("%d\n", i + 1);
        else{
            sum += (long long)cnt * a[i];
            cnt++;
        }
    }



    return 0;
}