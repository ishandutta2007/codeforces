#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#define endl '\n'
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void print(int x,int y){
    cout << char('a' + x - 1) << y << " ";
}
void solve(int &x,int &y, int moves){
    while(moves){
        if(x & 1){
            if(y == 8) x++;
            else y++;
        }
        else{
            if(y == 1) x++;
            else y--;
        }
        print(x, y);
        moves--;
    }
}
bool vis[10];
void solve(){
    int n;
    cin >> n;
    int x = 1, y = 1;
    print(1, 1);
    if(n <= 49){
        solve(x, y, n - 2);
        if(y != 8)
        {
            print(8, y);
            print(8, 8);
        }
        else{
            print(7, 8);
            print(8, 8);
        }
        return;
    }
    else{
        solve(x, y, 47);
        n -= 47;
        x++;
        print(x, y);
        n--;
        if(n == 2){
            print(8, y);
            print(8, 8);
            return;
        }
        if(n == 3){
            print(8, 1);
            print(8, 2);
            print(8, 8);
            return;
        }
        y = 8;
        print(x, y);
        n--;
        while(1){
            if(n == 2){
                print(8, y);
                print(8, 8);
                return;
            }
            n--;
            if(y == 2)
            {
                x = 8;
                print(x, y);
                break;
            }
            else{
                y--;
                print(x, y);
            }
        }
        vis[2] = 1;
        while(n > 1){
            fr(i, 1, 7){
                if(!vis[i]){
                    vis[i] = 1;
                    print(8, i);
                    break;
                }
            }
            n--;
        }
        print(8, 8);
    }
}

signed main()
{
    IO;
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    clock_t clk = clock();
    int t;
    // cin >> t;
    t = 1;
    fr(i, 1, t){
        solve();
    }
    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
}