#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <utility>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
const int M = 1007;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
 
 
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        for(int i = 1; i <= n; ++i){
            int x;
            cin >>x;
            ans = max(ans, x - i);
        }
        cout << ans << endl;
    }
    return 0;
}